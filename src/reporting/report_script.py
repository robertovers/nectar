import pandas as pd
import matplotlib.pyplot as plt 

def generate_report(datafile):

    sim_data = pd.read_csv(datafile)

    time = sim_data["time"]
    nectar = sim_data["nectar"]
    pollinated = sim_data["pollinated"]

    figure, axis = plt.subplots(3, 1)

    figure.suptitle("Nectar Simulation Report")

    figure.set_size_inches(8.27, 11.69)

    axis[0].axis("off")

    axis[1].plot(time, nectar)
    axis[1].set_title("Nectar in Hive")
    axis[1].set_ylabel("Nectar (milligrams)")
    axis[1].set_xlabel("Time (seconds)")

    axis[2].plot(time, pollinated)
    axis[2].set_title("No. of Pollinated Flowers")
    axis[2].set_ylabel("No. of Flowers")
    axis[2].set_xlabel("Time (seconds)")

    figure.tight_layout()
    plt.show()
    figure.savefig("plot.pdf")

if __name__ == '__main__':
    generate_report("reporting/sim_data.csv")

