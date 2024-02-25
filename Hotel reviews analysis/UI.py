from scrap_hotel_reviews import Scrapper
import streamlit as st
import re

class UI:

    def __init__(self) -> None:
        st.title("Hotel Review Analysis")
    
    def predict(self, hotel_name, reviews = []):
        '''Predict that wehter the hotel is good or bad'''
        if len(reviews) == 0:
            reviews = self.fetchReviews(hotel_name)
        return f"{hotel_name}, {reviews}"

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
    
    def fetchReviews(self, hotel_name, num_of_reviews):
        '''Fetching the review from the google review website using scrapper'''

        self.scrapper = Scrapper()
        return self.scrapper.scrap_data(hotel_name, num_of_reviews)
    
    def displayReview(self, hotel_name, num_of_reviews):
        '''Display the reviews on the website'''
        st.write("Display reviews:-")
        all_review = self.fetchReviews(hotel_name, num_of_reviews )
        if len(all_review) == 0:
            st.write("Sorry no reviews found")
        else:
            for review in all_review:
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
        