from scrap_hotel_reviews import Scrapper
import streamlit as st
import pickle as pkl
import pandas as pd
import re

class UI:

    def __init__(self) -> None:
        st.title("Hotel Review Analysis")
        self.all_review = []

    def predict(self, hotel_name, reviews = []):
        '''Predict that wehter the hotel is good or bad'''
        if len(reviews) == 0:
            reviews = self.fetchReviews(hotel_name, self.num_of_reviews)

        model = pkl.load(open('nlp_model/logistics_regression_model.pkl','rb'))
        prediction = model.predict(reviews)
        prediciton_result = self.get_prediction_result(prediction)
        st.write(f"The hotel {hotel_name} is {prediciton_result}")
        self.show_graph(prediction)
        return f"{hotel_name}, {reviews}"
    
    def show_graph(self, prediction):
        '''Show the graph of the prediction'''
        prediction_dict = {}
        prediction_dict['prediction'] = prediction
        prediction_df = pd.DataFrame(prediction_dict)
        neg_count = prediction_df[prediction_df["prediction"] == 0].count().values[0]
        pos_count = prediction_df[prediction_df["prediction"] == 1].count().values[0]

        graph_dict = {}
        graph_dict['neg_count'] = neg_count
        graph_dict['pos_count'] = pos_count
        graph_df = pd.DataFrame(graph_dict,index=[0])
        st.write("Prediction Graph:-")
        st.bar_chart(graph_df)

    def get_prediction_result(self, prediction):
        '''Convert the prediction into the human readable form'''
        prediction_dict = {}
        prediction_dict['prediction'] = prediction
        prediction_df = pd.DataFrame(prediction_dict)
        neg_count = prediction_df[prediction_df["prediction"] == 0].count().values[0]
        pos_count = prediction_df[prediction_df["prediction"] == 1].count().values[0]
        print(f'neg count: {neg_count} pos count: {pos_count}')
        if pos_count > neg_count:
            return "Good"
        elif pos_count < neg_count:
            return "Bad"
        else:
            return "Neutral"

    def input_details(self, hotel_names):
        '''Enter the details like the hotel name and the number of reviews onto which the user want to analyse'''

        self.hotel_name = st.selectbox("Enter the hotel name", hotel_names)
        self.num_of_reviews = st.slider("Enter the number of reviews in which you want to analyse.", min_value=1, max_value=100, step=1) 
        col1, col2 = st.columns(2)
        with col1:
            self.fetchReviews_button = st.button("Fetch reviews")
        with col2:
            self.predict_button= st.button("Predict")

        if self.fetchReviews_button :
            self.displayReview(self.hotel_name, self.num_of_reviews)
        # return self.hotel_name, self.num_of_reviews
        if self.predict_button:
            self.predict(self.hotel_name,self.all_review)
    
    def fetchReviews(self, hotel_name, num_of_reviews):
        '''Fetching the review from the google review website using scrapper'''

        self.scrapper = Scrapper()
        return self.scrapper.scrap_data(hotel_name, num_of_reviews)
    
    def displayReview(self, hotel_name, num_of_reviews):
        '''Display the reviews on the website'''
        st.write("Display reviews:-")
        self.all_review = self.fetchReviews(hotel_name, num_of_reviews )
        if len(self.all_review) == 0:
            st.write("Sorry no reviews found")
        else:
            for review in self.all_review:
                remove_read_more =str(review)
                matched = re.search(r'(\.|!)[^\.]*Read more$', remove_read_more)
                if matched:
                    remove_read_more = remove_read_more[0:matched.span()[0]]
                    print(remove_read_more)
                st.markdown(f">{remove_read_more}")



    # def (self, hotel_name, reviews:list):
    #     if st.button(label="Predict Price"):
    #         if len(reviews) == 0:
    #             st.write("Sorry! No reviews found for this hotel")
    #         else:
    #             st.success(self.predict(hotel_name, reviews))
    
    # def display_details(self):
        