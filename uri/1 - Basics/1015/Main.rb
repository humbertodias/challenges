def main()
	l1=gets.split()
    l2=gets.split()
    x1,y1 = [l1[0].to_f, l1[1].to_f]
    x2,y2 = [l2[0].to_f, l2[1].to_f]

    print("%.4f\n" %  Math.sqrt( (x2-x1) ** 2 + (y2-y1) ** 2 ) )
end

main()