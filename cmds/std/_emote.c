//#pragma save_binary

/*
// Help added by Brian (1/28/92)
// Revised by Buddha@TMI (8/1/92)
*/

#include <mudlib.h>

inherit DAEMON ;

int cmd_emote(string str) {
    string first,tail,insert;

    if(!str) {
      write("�㿴��������ḻ.\n");
      say(this_player()->query("c_name")+"�����ḻ�ı���.\n");
      return 1;
    }
    if (!wizardp(previous_object())) first = "-> ";
    else first = "";
    if (sscanf(str," %s",tail)==1) insert = "";
    else if (sscanf(str,"'%s",tail) == 1) insert = "";
    else insert = " ";
    write(wrap("���� : " + first + this_player()->query("c_name") +
	 insert + str));
    say(wrap(first + this_player()->query("c_name") + insert + str));
    return 1;
}

int
help() {
  write(@HELP
ָ���ʽ: emote <������>
����ָ�����������һ��ϵͳû��Ԥ��Ķ����ʡ�
ϵͳ�Ὣ����������ֺ���������������ʾ��ͬһ�����������￴��

����emote ��Ц
    ��ͬһ���������ﶼ�ῴ����->x��Ц (x=ʹ��ָ������)

���ָ���У�semote
HELP
);
  return 1;
}
/* EOF */
