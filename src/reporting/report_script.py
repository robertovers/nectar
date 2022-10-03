import sys
import pandas as pd
import matplotlib.pyplot as plt 
from datetime import datetime
from enum import Enum

def generate_report(datafile):

    # Read data
    sim_data = pd.read_csv(datafile)
    
    # Setup time axis units
    timescale_string = "Time (seconds)"
    if sim_data.iloc[-1]["time"] > 3600:
        sim_data["time"] = sim_data["time"].apply(lambda x : x / 3600)
        timescale_string = "Time (hours)"
    elif sim_data.iloc[-1]["time"] > 60:
        sim_data["time"] = sim_data["time"].apply(lambda x : x / 60)
        timescale_string = "Time (minutes)"

    # Create figure and subplots
    figure, axis = plt.subplots(3, 1)
    figure.suptitle("Nectar Simulation Report")
    figure.set_size_inches(8.27, 11.69)

    time = sim_data["time"]
    nectar = sim_data["nectar"]
    pollinated = sim_data["pollinated"]

    now = datetime.now()
    date_time = now.strftime("%d/%m/%Y %H:%M:%S")

    # Simulation details 
    axis[0].axis("off")
    axis[0].text(0, 0.3,
        f"Simulation run completed at {date_time}\n\n"
        + "Simulation parameters\n" 
        + f"Bees: {sys.argv[1]}\n"
        + f"Environment X dimensions: {sys.argv[2]}\n"
        + f"Environment Y dimensions: {sys.argv[3]}\n"
        + f"Soybean spawn probability: {sys.argv[4]}\n"
    )

    plt.style.use("ggplot")

    # Plot nectar graph
    axis[1].plot(time, nectar)
    axis[1].set_title("Nectar in Hive")
    axis[1].set_ylabel("Nectar (milligrams)")
    axis[1].set_xlabel(timescale_string)

    # Plot pollination graph
    axis[2].plot(time, pollinated)
    axis[2].set_title("Number of Pollinated Flowers")
    axis[2].set_ylabel("Pollinated flowers")
    axis[2].set_xlabel(timescale_string)

    figure.tight_layout()
    figure.savefig("nectar_report.pdf")


if __name__ == '__main__':

    generate_report("reporting/sim_data.csv")
