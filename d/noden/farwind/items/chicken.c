#include <mudlib.h>

inherit OBJECT;

void init()
{
	add_action( "eat_food", "eat" );
}

void create(){

	set_name("chicken","����");
	add( "id" , ({ "chicken" }) );
	set_short( "����" );
	set_long( "���ʵ����������ϡ�Զ��Ƶ꡻�洫�Ŀ��������˲���ʳָ��...\n");
   	set("unit","��");
   	set("weight", 15);
   	set("value",({200, "silver"}) );
	set("fresh",3600); // fresh is measured in seconds...
	call_out("not_fresh", query("fresh"),this_object() );
	set("is_fresh",1);
}

int eat_food(string arg)
{
	if( arg != "chicken" ) return 0;

	if(!query("is_fresh")){
		write("һ�ɳ����������㲻�ɵ���ס����...�찡...�����..!!\n");
		write("�㶪��һ�����˵ļ��⡣\n");
	tell_room( environment(this_player()), 
		this_player()->query("c_name")+"����һ�̳����˵Ŀ�����...\n",
		this_player() );
	

		remove();
		return 1;
	}

	write( 	"�����سԵ�����һ�̿�����������һ�������...:)\n" );
	tell_room( environment(this_player()), 
		this_player()->query("c_name")+"�Ե���һ�̿������������������һЩ...\n",
		this_player() );
		

	this_player()->receive_healing(30);
	remove();
	return 1;

}

void not_fresh(object who)
{
	object owner;
	owner = environment(who);
        if( owner && living(owner) )
	{
		write("���ŵ�һ�ɳ�ζ������������ʲ�ᶫ�����˵����ӡ�\n" );
        }
		set ("value", ({ 1, "silver" }));
		set_short( "���˵Ŀ���" );
		set_long( "���̿����Ѿ����ˣ����ܳ��ˡ�\n");
		set("is_fresh",0);
}
   	
