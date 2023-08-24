public class ThreadTest {
    public static void main(String[] args) {
        A a = new A();
        B b = new B(a);
        C c = new C(b);
        c.start();
    }
}

class A extends Thread {
    public void run() {
        System.out.println("A");
    }
}

class B extends Thread {
    public B(A a) {
        super(a);
    }

    public void run() {
        System.out.println("B");
    }
}

class C extends Thread {
    public C(B b) {
        super(b);
    }
}
