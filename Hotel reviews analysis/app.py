import pandas as pd
from UI import UI
# from pyvirtualdisplay import Display
# from scrap_hotel_reviews import Scrapper
from hotel_review_preprocessor import Preprocessor


if __name__ == "__main__":
    hotel_name_df = pd.read_csv("Hotelname.csv")
    hotel_name_df.drop_duplicates(inplace=True)
    # hotel_name_df
    ui = UI()
    ui.input_details(hotel_name_df["Hotel names"])
    # google_review_scrapper = Scrapper()    
    # google_review_scrapper.scrap_data("Taj hotel")
    # hotel_reviews = []
    # try:
    #     df = pd.read_csv("tmp_reviews.csv")
    #     preprocessor = Preprocessor(df)
    #     preprocessor.clean_data()
    #     hotel_reviews = df["reviews"].unique()
    #     # hotel_names = clean_hotel_names()
    # except Exception as error:
    #     print(error)
    # ui.predict_button(hotel_name, hotel_reviews)
    # display = Display(visible=0, size=(800,600))
    # display.start()
    # print(hotel_reviews)
    # print(len(hotel_reviews))
    # google_review_scrapper.quit_driver()
