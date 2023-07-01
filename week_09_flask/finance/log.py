import os
import logging


def setup_logging():
    # Set up logging configuration

    # Define the log file path
    log_file = "logs/app.log"

    # Create the log directory if it doesn't exist
    log_dir = os.path.dirname(log_file)
    os.makedirs(log_dir, exist_ok=True)

    # Create a logger object
    logger = logging.getLogger(__name__)

    # Set the logging level to DEBUG
    logger.setLevel(logging.DEBUG)

    # Create a file handler to write log messages to the log file
    file_handler = logging.FileHandler(log_file)
    file_handler.setLevel(logging.DEBUG)

    # Create a formatter to define the log message format
    formatter = logging.Formatter('%(asctime)s - %(levelname)s - %(message)s')

    # Set the formatter for the file handler
    file_handler.setFormatter(formatter)

    # Add the file handler to the logger
    logger.addHandler(file_handler)

    # Return the configured logger
    return logger
