package hotel.management.system;

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class HotelManagementSystem extends JFrame implements ActionListener {

	JLabel l1;
	JButton b1;

	public HotelManagementSystem() {

		setSize(700, 500); // setContentPane(300,300,1366,390); frame size
		setLayout(null);
		setLocation(30, 30);

		l1 = new JLabel("");
		b1 = new JButton("Next>>");

		b1.setBackground(Color.WHITE);
		b1.setForeground(Color.BLACK);

		JLabel lid = new JLabel("HOTEL MANAGEMENT SYSTEM");
		lid.setBounds(100, 30, 500, 100);
		lid.setFont(new Font("serif", Font.PLAIN, 30));
		lid.setForeground(Color.red);
		l1.add(lid);

		b1.setBounds(300, 300, 150, 70);
		l1.setBounds(0, 0, 1366, 390);

		l1.add(b1);
		add(l1);

		b1.addActionListener(this);
		setVisible(true);
	}

	public void actionPerformed(ActionEvent ae) {
		new Login().setVisible(true);
		this.setVisible(false);
	}

	public static void main(String[] args) {
		HotelManagementSystem window = new HotelManagementSystem();
		window.setVisible(true);
	}

}
