package com.hgu.oss;

import java.util.ArrayList;
import java.util.List;

public class FinanceStorage {
	List<Integer> storage = new ArrayList<Integer>();
	Finance finance = new Finance();
	int difference;
	int today;
	int yesterday;
	
	public void add() {
		storage.add(finance.calBalance());
	}
	public void printDifference() {
		today = storage.get(storage.size()-1);
		yesterday = storage.get(storage.size()-2); 
		difference = today - yesterday;
		if(difference > 0) // 만약 오늘 돈을 더 썼으면 
			System.out.printf("어제에 비해 %d원을 더 사용하였습니다.\n", difference);
		else {
			difference *= -1;
			System.out.printf("어제에 비해 %d원을 아끼셨습니다.\n", difference);
		}
	}

}
