if [ -d ./build ]; then
    cd build
    cmake -DCMAKE_BUILD_TYPE=Release ..
    make
    echo "Attempting to move executable to /usr/local/bin, please input your password if prompted"
    sudo mv ./calc /usr/local/bin
    # Verify if the move was successful
    if [ $? -eq 0 ]; then
        echo "Success: calc moved to /usr/local/bin."
    else
        echo "Error: calc not moved to /usr/local/bin."
        exit 1
    fi
else
    echo "No build directory found, please create ./build directory and rerun"
fi