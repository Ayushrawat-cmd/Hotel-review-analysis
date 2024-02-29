import re
import streamlit as st
import UI

class DisplayReview:
    def __init__(self, st:st) -> None:
        st.write("Display reviews:-")
        self.st = st
        review_file = open("reviews.txt", "w+")
        review_file.close()
    
    def displayReview(self, review_text):
        '''Display the reviews on the website'''

        if len(review_text) == 0:
            st.write("Sorry no reviews found")
        else:
            remove_read_more =str(review_text)
            matched = re.search(r'(\.|!)[^\.]*Read more$', remove_read_more)
            if matched:
                remove_read_more = remove_read_more[0:matched.span()[0]]
                print(remove_read_more)
                
            # write the review into the file
            review_file_write = open("reviews.txt", "a")
            review_file_write.write(remove_read_more)
            review_file_write.write("\n")
            review_file_write.close()

            res = UI.UI().predict_one([remove_read_more])
            col1, col2 = st.columns([3,1])
            if res == 1:
                with col1:
                    st.markdown(f">{remove_read_more}")
                with col2:
                    st.markdown(":green[Sentiment: 'Positive']")
            else:
                with col1:
                    st.markdown(f">{remove_read_more}")
                with col2:
                    st.markdown(":red[Sentiment: 'Negative']")
        
        
    
        