#include <iostream>
using namespace std;

//�ڵ���
class Node {
public:
    int data;//������
    Node* next;//ָ����

    Node(int value) : data(value), next(nullptr) {}//�в�Ĭ�Ϲ��캯������ʼ����һ�����ݣ���ָ��ָ���
};

//������
class LinkedList {
private:
    Node* head;//ָ��ͷ�ڵ��ָ��

public:
    LinkedList() : head(nullptr) {}//�޲�Ĭ�Ϲ��캯������ʼ��ͷָ��ָ���

    //����ͷ�ڵ�
    void insertAtBeginning(int value) {
        Node* newNode = new Node(value);//�����µĽڵ�ָ�룬���ҳ�ʼ������
        newNode->next = head;//��ͷָ�븳ֵ���½ڵ��ָ����
        head = newNode;//ͷָ��ָ���½ڵ�
    }

    void insertAtMiddle(int value, int position) {
        Node* newNode = new Node(value);
        Node* cur = head;
        int count = 0;//��������Ѱ��λ��position-1����ʼλ��Ϊ0
        while (count != position - 1) { //��������������position-1���������ͼ�1������cur����
            count++;
            cur = cur->next;
        }

            //�ҵ�֮�󣬽��½ڵ��ָ��ָ��position�Ľڵ㣬��position-1��ָ��ָ���½ڵ�
        //���curָ��գ�˵������λ�������һ���ڵ����һ����ֻҪ��cur��ָ��ָ���½ڵ�
        //if (cur == nullptr) {
        //    cur->next = newNode;
        //}
        //else {
        //    newNode->next = cur->next;
        //    cur->next = newNode;
        //}
        newNode->next = cur->next;
        cur->next = newNode;
        
    }


    //����
    void display() {
        Node* cur = head;//����һ����ʱָ�룬��ʼ��Ϊͷָ��
        while (cur != nullptr) { //����ʱָ�벻ָ���ʱ
            cout << cur->data << " ";//���ָ��ָ���������
            cur = cur->next;//ָ��ָ��ǰ�ڵ��ָ����
        }
        cout << endl;//����
    }

    //ɾ���ڵ�
    void deleteNode(int key) {
        Node* cur = head;//����һ����ʱָ�룬��ʼ��Ϊͷָ��
        Node* pre = nullptr;//����һ��ָ�룬ָ����һ���ڵ㣬��ʼ��ָ���

        //����ͷ�ڵ���Ǵ�ɾ���ڵ�����
        if (cur != nullptr && cur->data == key) {//�����ǰָ��û��ָ��գ���ͷָ��û��ָ��գ�������Ϊ�գ����ҵ�ǰ�ڵ�����������key
            head = cur->next;//ֱ�ӽ�ͷָ�����
            delete cur;//�ͷŵ�ǰָ��
            return;//����
        }

        //�����ɾ���ڵ����м�ڵ��β�ڵ�����
        while (cur != nullptr && cur->data != key) {//��û�����꣬���ҵ�ǰָ����������key
            pre = cur;//ָ��ǰ���ڵ��ָ�����
            cur = cur->next;//ָ��ǰ�ڵ��ָ�����
        }

        if (cur == nullptr) return;//�Ҳ���key������

        pre->next = cur->next;//ǰ���ڵ��ָ��ָ��ǰ�ڵ��ָ�룬����ǰ�ڵ㱻ɾ��
        delete cur;//�ͷŵ�ǰָ��
    }
};


int main() {

    LinkedList list1;
    list1.insertAtBeginning(3);
    list1.insertAtBeginning(3);
    list1.insertAtBeginning(3);
    list1.insertAtBeginning(3);
    list1.insertAtBeginning(3);
    list1.insertAtMiddle(123, 1);
    list1.insertAtMiddle(123, 5);

    list1.insertAtMiddle(123, 6);
    list1.display();

    return 0;
}