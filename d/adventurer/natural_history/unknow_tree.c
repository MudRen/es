#include <mudlib.h>
#define FRESH_TIME 600

inherit OBJECT;

void create()
{
	set_name("unknown plant","��ֵ�ֲ��");
	add( "id" , ({ "plant" }) );
	set_short("��ֵ�ֲ��");
	set_long(
		"����һ�꿴���������ֲ�����춸�����ֲ��̫ï�ܣ�\n"
		"��Ҳ����ȷ�����ǲ������ã�Ҳ���ðѻ���(cut)��������������\n"
		"���������ʲ��...\n"
	);
   	set("unit","��");
//   	set("cropp",1);
   	set("weight", 10000);
   	set("value",({ 0, "silver" }) );
	set("cropp",1);
	set("is_fresh",1);
}
void init()
{
    add_action("do_cropp","cut");
}    
int do_cropp( string arg )
{
     object obj;
     int i,n;
     string str;      
           
           if ( !arg || arg != "plant") {
           write("�����ʲ��??\n");
           return 1;
           }
           if ( !present("scissors",this_player()) ) {
           write("��û���ʺϵĹ����...\n");
           return 1;
           }
           seteuid(getuid());
           write("�����𻨼��������겻��ֲ�����������������ϸ�Ĺ۲�����\n");
           
           tell_room( environment(this_player()),
           "\n"+this_player()->query("c_name")+"�ó�һ�ѷ����Ļ�������·�ߵ�һ��ֲ���������\n"
           "����������������ϸ�۲�...\n\n", ({this_player()}) );
           
           switch( n= random(2) ) {
           case 0: obj = new("/d/noden/farwind/items/branz_herb");break;
           case 1: obj = new("/d/adventurer/natural_history/herb");break;
           default : break;
           }
           
           if (obj->query("c_name")=="������ҩ��")
           obj->set("need_skill",1);
           
           
           if ((int)obj->query("need_skill") < (int)this_player()->query_skill("natural_history")-1) {              
               
                write("������Բ���ѧ����Ȼ�������ʶ����϶�����һ"+obj->query("unit")+"Ұ����\n"
                +obj->query("c_name")+"����ܿ�İ���������...\n");      
               
                tell_room( environment(this_player()),
                "\n"+this_player()->query("c_name")+"˵��: �����ҵ�һ"+obj->query("unit")+"Ұ����"
                +obj->query("c_name")+"\n������׬����...\n\n", ({this_player()}) );
                this_player()->gain_experience(5*(int)obj->query("need_skill"));
                obj->move(this_player());
                remove();
                return 1;
                } 
           
           else {
               
                write("�����û���������⣬������ûʲ���ð�..��˳�ְ�������·��\n");
               
                tell_room( environment(this_player()),
                "\n"+this_player()->query("c_name")+"�ƺ���֪���ɵ���ֲ����ʲ�ᣬ������\n"
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
