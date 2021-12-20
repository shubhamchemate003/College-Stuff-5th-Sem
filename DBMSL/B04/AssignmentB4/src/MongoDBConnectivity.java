import com.mongodb.client.FindIterable;
import com.mongodb.client.MongoCollection;
import com.mongodb.client.MongoDatabase;
import com.mongodb.client.model.Filters;
import com.mongodb.client.model.Updates;
import java.util.Scanner;
import java.util.Iterator;
import org.bson.Document;
import com.mongodb.MongoClient;

public class MongoDBConnectivity{
	
	@SuppressWarnings({ "unused", "resource" })
	public static void main(String args[]) {
		try {
			// for input
			Scanner sc = new Scanner(System.in);
			
			String name,email,pgUni,pgCourse;
			int rollNo;
			
			System.out.println("Establishing Connection to the database...\n");
			
			MongoClient mongo= new MongoClient("localhost",27017);
			MongoDatabase database= mongo.getDatabase("assignment12");
			
			System.out.println("Conncection Established");
			
			MongoCollection<Document> collection=database.getCollection("students");
			
			int choice=0;
			boolean cont=true;
			
			while(cont) {
				System.out.print("Enter the opereation you want to perform:\n "
						+ "\n1.Insert a student record"
						+ "\n2.Display all documents"
						+ "\n3.Search for a student"
						+ "\n4.Update a student record"
						+ "\n5.Delete a student record"
						+ "\n6.Exit\n\n"
						);
				
				choice=sc.nextInt();
				switch(choice) 
				{
				case 1: 
				{
					
					System.out.println("Enter the student rollNo: ");
					String x=sc.next();
					rollNo=Integer.valueOf(x);
					FindIterable<Document> iterDoc = collection.find(new Document("_id",rollNo));
					Iterator<Document> it = iterDoc.iterator();
					if(it.hasNext()) {
						System.out.println("Student record already present\n");
					}
					else {
						System.out.println("Enter the student name: ");
						name=sc.next();
						System.out.println("Enter the email: ");
						email=sc.next();
						System.out.println("Enter the University name: ");
						pgUni=sc.next();
						System.out.println("Enter the PG Course name: ");
						pgCourse=sc.next();
						
						Document document = new Document("_id",rollNo)
												.append("rollNo", rollNo)
												.append("name",name)
												.append("email",email)
												.append("university",pgUni)
												.append("PG Course",pgCourse);
						collection.insertOne(document);
						System.out.println("Student Record Inserted");
						
					}
					break;
				}
				case 2:
				{
					FindIterable<Document> iterDoc = collection.find();
					Iterator<Document> it = iterDoc.iterator();
					if(it.hasNext()) {
						while (it.hasNext()) {
							System.out.println(it.next());
						}	
					}
					else {
						System.out.println("No records found\n");
					}
					break;
				}
				case 3:
				{
					System.out.print("\nEnter the roll no you want to search: ");
					int sid=sc.nextInt();
					FindIterable<Document> iterDoc = collection.find(new Document("_id",sid));
					Iterator<Document> it = iterDoc.iterator();
					if(it.hasNext()) {
						System.out.println("Student record found\n");
						while(it.hasNext()) {
							System.out.println(it.next());
						}
					}
					else {
						System.out.println("Student record not found\n");
					}
					break;
				}
				case 4:
				{
					int subChoice;
					System.out.print("\nEnter the roll no whose data you want to update: ");
					int sid=sc.nextInt();
					FindIterable<Document> iterDoc = collection.find(new Document("_id",sid));
					Iterator<Document> it = iterDoc.iterator();
					if(it.hasNext()) {
						System.out.println("\nSelect the attribute you want to update: "
								+ "\n1.Name"
								+ "\n2.Email"
								+ "\n3.University"
								+ "\n4.PG Course\n\n");
						subChoice=sc.nextInt();
						switch(subChoice) 
						{
						case 1:
						{
							System.out.println("Enter the new name: ");
							String newName=sc.next();
							collection.updateOne(Filters.eq("_id", sid), Updates.set("fName", newName));
							System.out.println("Record Updated\n");
							break;
						}
						case 2:
						{
							System.out.println("Enter the new email: ");
							String newEmail=sc.next();
							collection.updateOne(Filters.eq("_id", sid), Updates.set("email", newEmail));
							System.out.println("Record Updated\n");
							break;
						}
						case 3:
						{
							System.out.println("Enter the new university: ");
							String newPgUni=sc.next();
							collection.updateOne(Filters.eq("_id", sid), Updates.set("fName", newPgUni));
							System.out.println("Record Updated\n");
							break;
						}
						case 4:
						{
							System.out.println("Enter the new PG course: ");
							String newPgCourse=sc.next();
							collection.updateOne(Filters.eq("_id", sid), Updates.set("fName", newPgCourse));
							System.out.println("Record Updated\n");
							break;
						}
						default:
						{
							System.out.print("Enter valid choice");
						}
						}
						break;
					}
					else {
						System.out.println("No such student record found\n");
					}
					break;
				}
				case 5:
				{
					System.out.print("\nEnter the roll no of student whose data you want to delete: ");
					int sid=sc.nextInt();
					FindIterable<Document> iterDoc = collection.find(new Document("_id",sid));
					Iterator<Document> it = iterDoc.iterator();
					if(it.hasNext()) {
						collection.deleteOne(Filters.eq("_id", sid));
						System.out.println("Student Record Deleted\n");
					}
					else {
						System.out.println("No such record is found\n");
					}
					break;
				}
				case 6:
				{
					System.out.println("Thank you");
					cont=false;
					break;
				}
				default:
				{
					System.out.println("Please Enter valid choice: ");
					break;
				}
				}
			}			
		}
		catch(Exception e) {
			e.printStackTrace();
		}		
	}
}