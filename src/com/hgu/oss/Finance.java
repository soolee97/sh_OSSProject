package com.hgu.oss;

public class Finance {
	private int balance; // 내가 가지고 있는 돈 
	private int deposit; // 내가 하루 얻은 돈 
	private int withdraw; // 내가 지출한 돈 
	
	public Finance() {}
	
	public Finance(int balance, int deposit, int withdraw) {
		//super();
		this.balance = balance;
		this.deposit = deposit;
		this.withdraw = withdraw;
	}
	
	public int getDeposit() {
		return deposit;
	}
	public void setDeposit(int deposit) {
		this.deposit = deposit;
	}
	public int getWithdraw() {
		return withdraw;
	}
	public void setWithdraw(int withdraw) {
		this.withdraw = withdraw;
	}
	public int getBalance() {
		return balance;
	}
	public void setBalance(int balance) {
		this.balance = balance;
	}
	public int calBalance(){
		balance = balance + deposit - withdraw;
		System.out.printf("%d원 남았습니다.\n", balance);
		System.out.println("오늘 하루도 고생 많았어요!");
		return balance;
	}	
}
