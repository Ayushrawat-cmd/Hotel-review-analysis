import re
import streamlit
from UI import UI
class DisplayReview:
    def __init__(self, st:streamlit) -> None:
        self.st = st
    
    def displayReview(self, review):
        '''Display the reviews on the website'''
        
        remove_read_more =str(review)
        matched = re.search(r'(\.|!)[^\.]*Read more$', remove_read_more)
        if matched:
            remove_read_more = remove_read_more[0:matched.span()[0]]
            print(remove_read_more)
        # st.session_state.all_review.append(remove_read_more)
        self.st.markdown(f">{remove_read_more}")
    
        