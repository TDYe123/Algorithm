package ̰�ķ�;
 
class RenWu implements Runnable{
	//��дrun()����
	public void run()
	{
		//��ȡ��ǰ�̵߳�����
		System.out.println("��ǰ�̣߳�"+Thread.currentThread().getName());
		for(int i=0;i<30;i++)
		{
			System.out.print("A");
			
		}
	}
}
public  class RunnableDemo{
	public static  void main(String[] args){
		//����һ���������
		RenWu rw=new RenWu();
		//��ʵ�ֵ�Runnable���ʵ�����빹�캯��
		Thread thread=new Thread(rw);
		thread.start();
		//��ȡ���̵߳�����
		System.out.println("���̣߳�["+Thread.currentThread().getName()+"]");
		for(int i=0;i<30;i++)
		{
			System.out.print("C");
		}
	}
}