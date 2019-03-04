#include <mudlib.h>
#define FRESH_TIME 600

inherit OBJECT;

void create()
{
	set_name("unknown rock","��ֵ�ʯͷ");
	add( "id" , ({ "rock" }) );
	set_short("��ֵ�ʯͷ");
	set_long(
		"����һ�ſ����������ʯͷ������춱�ɳʯ��ס�ˣ�ֻ����һ�����\n"
		"¶���ر���Ҳ���ܷǳ�ȷ������ʲ�ᣬҲ������ڳ�������\n"
		"���������ʲ��...\n"
	);
   	set("unit","��");
   	set("dig",1);
   	set("weight", 10000);
   	set("value",({ 0, "silver" }) );
	set("is_fresh",1);
}
void init()
{
      add_action("do_dig","dig");
}
int do_dig( string arg )
{
     object obj;
     int i,n;
     string str;      
           
           if ( !arg || arg != "rock") {
           write("������ʲ��??\n");
           return 1;
           }
           seteuid(getuid());
           write("��˫�ֲ��ã�����Ź�ʯͷ���˳�����������ϸ�Ĺ۲�����\n");
           
           tell_room( environment(this_player()),
           "\n"+this_player()->query("c_name")+"˫�ֲ��ã���·�ߵ�һ��ʯͷ���˳���\n"
           "����������������ϸ�۲�...\n\n", ({this_player()}) );
           
           switch( n= random(2) ) {
           case 0: obj = new("/d/adventurer/natural_history/stone");break;
           case 1: obj = new("/d/adventurer/natural_history/gem");break;
           default : break;
           }
           
           if (obj->query("c_name")=="Сʯ��") {
           obj->set("need_skill",1);
           str = "��ͨ��\n";
           }
           else str = "������\n";
           if ((int)obj->query("need_skill") < (int)this_player()->query_skill("natural_history")-1) {              
               
                write("������Բ���ѧ����Ȼ�������ʶ����϶�����һ"+obj->query("unit")+ str
                +obj->query("c_name")+"����ܿ�İ���������...\n");      
               
                tell_room( environment(this_player()),
                "\n"+this_player()->query("c_name")+"˵��: �����ҵ�һ"+obj->query("unit")+"�����"
                +obj->query("c_name")+"������׬����...\n\n", ({this_player()}) );
               
                this_player()->gain_experience(5*(int)obj->query("need_skill"));
                obj->move(this_player());
                remove();
                return 1;
                } 
           
           else {
               
                write("�����û���������⣬������ûʲ���ð�..��˳�ְ�������·��\n");
               
                tell_room( environment(this_player()),
                "\n"+this_player()->query("c_name")+"�ƺ���֪���ڳ��Ķ�����ʲ�ᣬ������\n"
                "����·��...\n\n",({this_player()}) );
               
                remove();
                return 1;
                }
                }
int move(mixed ob)
{
	if ( ob && living(ob))
        call_out("not_fresh", FRESH_TIME, this_object() );
	return ::move(ob);
}

void not_fresh(object what)
{
	remove();
}
