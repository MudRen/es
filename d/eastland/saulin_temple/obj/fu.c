#include <mudlib.h>

inherit OBJECT;
int in_use;

void init()
{
	add_action( "catch_tail", "catch" );
}

void create(){

	set_name("wind tail","��֮β��");
        add("id",({"wind","tail",}) );  
	set_short("��֮β��");
	set_long(@C_LONG
��֮β����һֻСС��β��,���Ƿ���Сʱ��̰���ײ�ϵ���β��... 
�������������ץ����β��,���԰�����β�Ͳ�������,ȴ�����ٹ�͵�ó����� 
��˵ץס(catch)��ֻβ��(tail)��,�㽫ӵ�з���ٶ�...
C_LONG
                 );
        set("value" , ({10,"silver"}) );
        set("weight",10);
	set("unit","ֻ");
}

int catch_tail(string arg)
{
        if( arg != "tail") return 0;
        if (!in_use)
       {  
        in_use =1;
        
	set("prevent_drop",1); 
        set_short("��֮β��������Ч����"); 

	write( 
"��ץס�˷�֮β�ͣ�һ�����������Դ���������Լ�������... \n"
	);
	tell_room( environment(this_player()), 
		this_player()->query("c_name")+"ץס�˷�֮β�ͣ�һ���紵��������������\n",
		this_player() );
 
	this_player()->modify_stat("dexterity",2);
	call_out("restore",30,this_player());
	return 1;
        }
}

void restore(object player){

	tell_object(player, 
		"Χ���������Եķ��������ı�С��...\n");
	this_player()->modify_stat("dexterity",-2);
        remove(); 
}
