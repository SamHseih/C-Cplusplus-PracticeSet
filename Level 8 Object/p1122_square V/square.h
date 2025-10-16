class Square
{	
	public:
		Square();
		Square(int n);
		int getLen(); 
		int area();
		void setLen(int n);
		friend  int cmpSquare(Square &q1, Square &q2);
		
		
	private:
		int len;
		int Area;
};
int cmpSquare(Square &q1, Square &q2);
