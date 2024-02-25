import math
from selenium import webdriver
from hotel_review_preprocessor import Preprocessor
from selenium.webdriver import Keys
import pandas as pd 
import numpy as np
from time import sleep
import re

class Scrapper:
        
    def __init__(self):
        '''Initialise the driver'''
        options = webdriver.ChromeOptions()
        options.add_argument("--headless")
        options.add_argument('window-size=1200x600')
        self.review_dict = {}
        self.driver = webdriver.Chrome(options= options)
        

    def handle_infinite_reload(self,max_scroll_times =11):
        '''Infinite reload handler in the google review page'''

        last_height = self.driver.execute_script("return document.body.scrollHeight") 
        # last height of the window

        curr_scroll_times = 0
        while curr_scroll_times<max_scroll_times:
            # Scroll down 
            start = self.driver.execute_script("return window.pageYOffset;")
            if curr_scroll_times == 0:
                start = 0
            for i in range(start,last_height,3):
                self.driver.execute_script(f"window.scrollTo(0, {i});")

            # Calculate new scroll height and compare with last scroll height
            new_height =self.driver.execute_script("return document.body.scrollHeight")
            # last_height = self.driver.execute_script("return window.pageYOffset;")
            # sleep(2)
            # if new_height == last_height:
            #     break
            last_height = new_height
            print(curr_scroll_times)
            curr_scroll_times+=1

    def scrap_data(self, hotel_name, num_of_reviews=100):   
        '''Scrapping the data from the google reviews'''
        self.driver.get("https://www.google.com/webhp?hl=en&sa=X&ved=0ahUKEwi7n_msosGEAxWZ8zgGHcVJC5QQPAgJ")
        sleep(2)
        try:
            # getting the element of searching the bar
            searchbar= self.driver.find_element(by="xpath", value='//*[@id="APjFqb"]')
            sleep(2)
        finally:
            # search the review for the given hotel name
            searchbar.send_keys(f"{hotel_name} reviews" + Keys.ENTER)
            sleep(3)
            try:      
                # get the review link element
                review_link = self.driver.find_element(by="xpath", value='//a[@class="hqzQac"]')
                sleep(1)
                review_link.send_keys(Keys.ENTER)
            except Exception as error:
                print(error)
            finally:
                try:
                    self.handle_infinite_reload(max_scroll_times=math.ceil(num_of_reviews/9))
                    sleep(2)
                    reviews = self.driver.find_elements(by="xpath", value='//div[@class="K7oBsc"]/div/span')
                    sleep(5)
                    # print(reviews)
                    all_reviews = []
                    for review in reviews[0:min(len(reviews), num_of_reviews+20)]:

                        # removing the read more line from the review
                        print(review.text)
                        remove_read_more_text = review.text
                        # sleep(1)
                        
                        all_reviews.append(remove_read_more_text)
                        sleep(1)
                    

                    self.driver.quit()

                    print(len(all_reviews))
                    self.review_dict["reviews"] = all_reviews
                    df = pd.DataFrame(self.review_dict)

                    self.review_dict.clear() # clearing up the dictionary

                    # preprocessing the datafram
                    self.preprocessor = Preprocessor(df) 
                    self.preprocessor.clean_data() 

                    return np.array(df["reviews"])[0 :num_of_reviews+1]
                    # df.to_csv('tmp_reviews.csv')
                except Exception as error:
                    print(error)
                    return []





