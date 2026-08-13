class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {

        ListNode dummy = new ListNode(-1);
        ListNode temp = dummy;

        ListNode temp1 = l1;
        ListNode temp2 = l2;

        int carry = 0;

        // Jab dono lists me nodes hain
        while (temp1 != null && temp2 != null) {

            int sum = temp1.val + temp2.val + carry;

            temp.next = new ListNode(sum % 10);

            carry = sum / 10;

            temp = temp.next;
            temp1 = temp1.next;
            temp2 = temp2.next;
        }

        // Agar l1 me nodes bach gaye
        while (temp1 != null) {

            int sum = temp1.val + carry;

            temp.next = new ListNode(sum % 10);

            carry = sum / 10;

            temp = temp.next;
            temp1 = temp1.next;
        }

        // Agar l2 me nodes bach gaye
        while (temp2 != null) {

            int sum = temp2.val + carry;

            temp.next = new ListNode(sum % 10);

            carry = sum / 10;

            temp = temp.next;
            temp2 = temp2.next;
        }

        // Last me carry bach gaya
        if (carry != 0) {
            temp.next = new ListNode(carry);
        }

        return dummy.next;
    }
}