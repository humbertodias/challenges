for file in $(find . -type f -name 'Main2.py');
   do 
	   dir=`echo $file | rev |  cut -d/ -f2 | rev`

	   echo "$file #### $dir"

	   urionlinejudge submit "$file" "$dir" --language python
done
