
import java.sql.*;

public class Main {
	
	static final String url = "jdbc:mysql://localhost:3306/a08_database";
	static final String user = "root";
	static final String pass = "root123";
	
	public static void readDB(String query) throws Exception {
		Class.forName("com.mysql.cj.jdbc.Driver");
		Connection con = DriverManager.getConnection(url, user, pass);
		Statement st = con.createStatement();
		
		ResultSet rs = st.executeQuery(query);
		System.out.println("Successfully Executed(Read)\n");
		
		System.out.println("ResultSet: ");
		while (rs.next()) {
			String retrivedData = rs.getInt(1)+" "+rs.getString(2)+" "+rs.getString(3);
			System.out.println(retrivedData);
		}
		
		st.close();
		con.close();
	}
	
	public static void modifyDB(String query) throws Exception {
		Class.forName("com.mysql.cj.jdbc.Driver");
		Connection con = DriverManager.getConnection(url, user, pass);
		Statement st = con.createStatement();
		
		
		st.executeUpdate(query);
		
		System.out.println("Successfully Executed(Modify)");
		
		st.close();
		con.close();
	}
	
	public static void UpdateGrade(int roll_no, String newGrade) throws Exception {
		Class.forName("com.mysql.cj.jdbc.Driver");
		Connection con = DriverManager.getConnection(url, user, pass);
		
		String query = "update student set grade=? where roll_no=?";
		PreparedStatement st = con.prepareStatement(query);
		
		st.setString(1, newGrade);
		st.setInt(2, roll_no);
		st.executeUpdate();
		
		System.out.println("Successfully Executed(Modify)");
		
		st.close();
		con.close();
	}

	public static void main(String[] args) throws Exception {
		
		String query1 = "create table student (" + 
				"    roll_no int not null primary key auto_increment," + 
				"    name varchar(100)," + 
				"    grade varchar(10)" + 
				")";
		String query2 = "insert into student (name, grade)" + 
				"values ('Tony', 'A+')," + 
				"('Natasha', 'B')," + 
				"('Steve', 'A+')," + 
				"('Peter', 'B')," + 
				"('Stephen Strange', 'A')";
		String query3 = "select * from student";
		String query4 = "update student set grade='A+' where roll_no=5";
		String query5 = "delete from student where roll_no=2";
		
//		modifyDB(query5);
//		readDB(query3);
		
//		prepared statement on update query
		int roll_no = 5;
		String grade = "A";
		UpdateGrade(roll_no, grade);
	}

}