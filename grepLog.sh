while IFS= read -r line; do
    echo $line
    sed -i '/^[[:space:]]*$/d' $line
done < <(find benchmark/ -name "*.log")