package ̰�ķ�;

public class ComplexNumber2
{
	private int real;
	private int image;

	public ComplexNumber2(int a,int b)
	{
		real=a;
		image=b;
	}

	public void biaodashi()
	{
		System.out.println("="+real+"+"+image+"i");
	}

	public int RealPart()
	{
		System.out.println("a="+real);
		return real;
	}
		public int ImagePart()
	{
		System.out.println("b="+image);
		return image;
	}
	public void add(ComplexNumber2 c){
		int a,b;
		a=this.real+c.real;
		b=this.image+c.image;
		System.out.println("(a1+a2)+(b1+b2)i="+a+"+"+b+"i");
	}

	public void mul(ComplexNumber2 c){
		int a,b;
		a=this.real*c.real-this.image*c.image;
		b=this.image*c.real+this.real*c.image;
		System.out.println("(a1+a2)+(b1+b2)i="+a+"+"+b+"i");
	}
	public static void main(String[] args) 
	{
	   int a1,a2,b1,b2;
		ComplexNumber2 x=new ComplexNumber2(3,4);
		ComplexNumber2 y=new ComplexNumber2(1,2);
		//x.getvalue(1,2);
		//y.getvalue(3,4);
		System.out.print("���ʽ1");
		x.biaodashi();
		System.out.print("���ʽ2");
		y.biaodashi();
		System.out.println("���ʽ1��ʵ�����鲿��");
		a1=x.RealPart();b1=x.ImagePart();
		System.out.println("���ʽ2��ʵ�����鲿��");
		a2=y.RealPart(); b2=y.ImagePart();
		System.out.println("���ʽ1��2���֮��Ϊ");
		x.add(y);
		System.out.println("���ʽ1��2���Ϊ");
	    x.mul(y);

	}
}
