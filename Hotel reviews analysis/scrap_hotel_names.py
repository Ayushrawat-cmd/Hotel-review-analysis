import pandas as pd
from selenium import webdriver
from selenium.webdriver import Keys
from time import sleep
import re

#59 page expedia hotels
for page in range(2,102):

    website = f"https://www.expedia.co.in/All-India-Hotels.d80-p{page}.Travel-Guide-City-All-Hotels"
    # "[^'].*[^']"
    driver = webdriver.Chrome()

    driver.get(website)

    sleep(5)
    hotel_names = [hotel_link.text for hotel_link in driver.find_elements(by='xpath', value='//*[@id="links-1"]/div/div[2]/div/div[1]/ul/li/a')]
    print(hotel_names)

    tmp_dict = {}
    tmp_dict["Hotel names"] = hotel_names

    df = pd.DataFrame(tmp_dict)
    df.to_csv('Hotelname.csv', index=False, header=False, mode='a')
    sleep(5)
    # //*[@id="__next"]/div/main/div[3]/div[1]/div[1]/div[2]/div/div/ol/li[1]/div/article/div[2]/div[1]/section/h2/button/span
driver.quit()
    # //*[@id="tabs-74-panel-3"]