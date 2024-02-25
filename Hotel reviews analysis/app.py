import pandas as pd
from UI import UI
# from pyvirtualdisplay import Display
# from scrap_hotel_reviews import Scrapper
from hotel_review_preprocessor import Preprocessor


if __name__ == "__main__":
    hotel_name_df = pd.read_csv("Hotelname.csv")
    hotel_name_df.drop_duplicates(inplace=True)
    ui = UI()
    ui.input_details(hotel_name_df["Hotel names"])
