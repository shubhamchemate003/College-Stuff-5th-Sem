import com.mongodb.client.FindIterable;
import com.mongodb.client.MongoCollection;
import com.mongodb.client.MongoDatabase;
import com.mongodb.client.model.Filters;
import com.mongodb.client.model.Updates;
import java.util.Iterator;
import org.bson.Document;
import com.mongodb.MongoClient;
import java.util.concurrent.ThreadLocalRandom;

public class MongoDBConnectivity {

	@SuppressWarnings({ "unused", "resource" })
	public static void main(String args[]) throws Exception {

		System.out.println("Establishing Connection to the database...\n");

		MongoClient mongo = new MongoClient("localhost", 27017);
		MongoDatabase database = mongo.getDatabase("b04_db");

		System.out.println("Conncection Established");

		MongoCollection<Document> collection = database.getCollection("students");

		String[] nameOfStudents = { "Tony", "Steve", "Stephen", "Loki" };
		String[] subjects = { "OOP", "DSA", "DBMS", "CN", "OS" };

//		insertion
		{
			int roll_num = 1;
			for (int i = 0; i < nameOfStudents.length; i++)
				for (int j = 0; j < subjects.length; j++) {

					int marks = ThreadLocalRandom.current().nextInt(70, 100 + 1);

					Document doc = new Document("_id", roll_num).append("name", nameOfStudents[i])
							.append("subject", subjects[j]).append("marks", marks);

					collection.insertOne(doc);

					roll_num++;
				}
			
			System.out.println(roll_num-1 + " records are successfully inserted.\n");
		}

//		read
		{
			System.out.println("Reading records from collection:");
			FindIterable<Document> iterDoc = collection.find();
			Iterator<Document> it = iterDoc.iterator();
			if (it.hasNext())
				while (it.hasNext())
					System.out.println(it.next());
			else
				System.out.println("No records found");
			System.out.println("Record reading done.\n");
		}

//		find details of student with given roll number
		{
			int roll_num = 8;
			System.out.println("Getting details of student having roll number " + roll_num);
			FindIterable<Document> iterDoc = collection.find(new Document("_id", roll_num));
			Iterator<Document> it = iterDoc.iterator();
			if (it.hasNext()) {
				while (it.hasNext()) {
					System.out.println(it.next());
				}
			} else {
				System.out.println("Student record not found.");
			}
			
			System.out.println("Reading done.\n");
		}

//		update
		{
			int roll_num = 2;
			System.out.println("Updating marks of student having roll number " + roll_num);
			collection.updateOne(Filters.eq("_id", roll_num), Updates.set("marks", 100));
			FindIterable<Document> iterDoc = collection.find(new Document("_id", roll_num));
			Iterator<Document> it = iterDoc.iterator();
			if (it.hasNext()) {
				System.out.println("Details of student after update operation:");
				while (it.hasNext()) {
					System.out.println(it.next());
				}
			} else {
				System.out.println("Student record not found.");
			}
			
			System.out.println("Updata done.\n");
		}

//		delete
		{
			int roll_num = 2;
			System.out.println("Deleting record of student having roll number " + roll_num);
			FindIterable<Document> iterDoc = collection.find(new Document("_id", roll_num));
			Iterator<Document> it = iterDoc.iterator();
			if (it.hasNext()) {
				collection.deleteOne(Filters.eq("_id", roll_num));
				System.out.println("Student Record Deleted.");
			} else {
				System.out.println("No such record is found.");
			}
			
			System.out.println("Delete operation done.\n");
		}

	}
}