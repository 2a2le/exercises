// Alex B

public class MyQueue<T> {
  private class QueueNode<T> {
    T data;
    QueueNode<T> next;

    public QueueNode(T data) {
      this.data = data;
    }
  }

  private QueueNode<T> first;
  private QueueNode<T> last;

  private void add(T item) {
    QueueNode<T> node = new QueueNode<T>(item);
    if (last == null) {
      first = node;
    } else {
      last.next = node;
    }
    last = node;
  }

  
}
