from scrap_hotel_reviews import Scrapper
import streamlit as st
import pickle as pkl
import pandas as pd
import os
import matplotlib.pyplot as plt

class UI:

    st.title("Hotel Review Analysis")
    def __init__(self) -> None:
        # self.predict_button_disable = True
        st.session_state.disabled = True
    
    def predict_one(self,review):
        model = pkl.load(open('nlp_model/logistics_regression_model.pkl','rb'))
        prediction = model.predict(review)
        return prediction

    def predict(self, hotel_name):
        '''Predict that wehter the hotel is good or bad'''
        reviews = open("reviews.txt", "r").readlines()
        if(len(reviews) == 0):
            self.fetchReviews(hotel_name,self.num_of_reviews)

        model = pkl.load(open('nlp_model/logistics_regression_model.pkl','rb'))
        prediction = model.predict(reviews)
        prediciton_result = self.get_prediction_result(prediction)
        st.header(f"The hotel {hotel_name} has :red[{prediciton_result}] reviews")
        os.remove("reviews.txt")
        try:
            self.show_graph(prediction)
        except Exception as error:
            print(error)
        return f"{hotel_name}, {reviews}"
    
    def show_graph(self, prediction):
        '''Show the graph of the prediction'''
        prediction_dict = {}
        prediction_dict['prediction'] = prediction
        prediction_df = pd.DataFrame(prediction_dict)
        neg_count = prediction_df[prediction_df["prediction"] == 0].count().values[0]
        pos_count = prediction_df[prediction_df["prediction"] == 1].count().values[0]
        fig, ax = plt.subplots()
    
        ax.pie([neg_count, pos_count], labels=["Negative reviews", "Positive reviews"],autopct='%1.0f%%' )
        st.write(f"Prediction Graph:- ")
        st.pyplot(fig)

    def get_prediction_result(self, prediction):
        '''Convert the prediction into the human readable form'''
        pos_count = 0
        neg_count = 0
        for i in prediction:
            if i == 1:
                pos_count+=1
            else:
                neg_count+=1
        print(f'neg count: {neg_count} pos count: {pos_count}')
        if pos_count > neg_count:
            return "POSITIVE"
        elif pos_count < neg_count:
            return "NEGATIVE"
        else:
            return "NEUTRAL"

    def input_details(self, hotel_names):
        '''Enter the details like the hotel name and the number of reviews onto which the user want to analyse'''

        self.hotel_name = st.selectbox("Enter the hotel name", hotel_names)
        self.num_of_reviews = st.slider("Enter the number of reviews in which you want to analyse.", min_value=1, max_value=100, step=1) 
        col1, col2 = st.columns(2)
        with col1:
            self.fetchReviews_button = st.button("Fetch reviews")

        if self.fetchReviews_button :
            self.fetchReviews(self.hotel_name, self.num_of_reviews)
            st.session_state.disabled = False

        with col2:
            self.predict_button= st.button("Predict", disabled=st.session_state.disabled)

        # return self.hotel_name, self.num_of_reviews
        if self.predict_button:
            self.predict(self.hotel_name)

    def fetchReviews(self, hotel_name, num_of_reviews):
        '''Fetching the review from the google review website using scrapper'''

        self.scrapper = Scrapper()
        return self.scrapper.scrap_data(hotel_name, num_of_reviews,st)
    
    # def displayReview(self, hotel_name, num_of_reviews):
    #     '''Display the reviews on the website'''
    #     review_file = open("reviews.txt", "w")
    #     st.write("Display reviews:-")
    #     all_reviews = self.fetchReviews(hotel_name, num_of_reviews )
    #     if len(all_reviews) == 0:
    #         st.write("Sorry no reviews found")
    #     else:
    #         for review in all_reviews:
    #             remove_read_more =str(review)
    #             matched = re.search(r'(\.|!)[^\.]*Read more$', remove_read_more)
    #             if matched:
    #                 remove_read_more = remove_read_more[0:matched.span()[0]]
    #                 print(remove_read_more)
                
    #             # write the review into the file
    #             write_review_file = open("reviews.txt", "a")
    #             write_review_file.write(remove_read_more)
    #             write_review_file.write("\n")
    #             write_review_file.close()

    #             res = self.predict_one([remove_read_more])
    #             col1, col2 = st.columns([3,1])
    #             if res == 1:
    #                 with col1:
    #                     st.markdown(f">{remove_read_more}")
    #                 with col2:
    #                     st.markdown(":green[Sentiment: 'Positive']")
    #             else:
    #                 with col1:
    #                     st.markdown(f">{remove_read_more}")
    #                 with col2:
    #                     st.markdown(":red[Sentiment: 'Negative']")
                        
        

