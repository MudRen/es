#include <mudlib.h>

inherit OBJECT;
int in_use;

void init()
{
	add_action( "drink_wine", "drink" );
}

void create(){

	set_name("angel kiss","��ʹ֮��");
        add("id",({"wine","kiss","angel kiss"}) );  
	set_short("��ʹ֮��");
	set_long(@C_LONG
��ʹ֮����һ������ʹף�����ľ�,�����еĺ�ɫ����ɢ����һ�����ض����˵����� 
������Դ,�ഫ��һ����������Թ�ļ�����Ů�ɵĹ���,��������Ԥ�Ⱞ��. ���˵ص� 
��ʹ֮��,������ʹ���Ƶ�,��˵����(drink)�Ɑ��(wine)��,���������ޱȵ�����...
C_LONG
                 );
        set("value" , ({10,"silver"}) );
        set("weight",10);
	set("unit","��");
}

int drink_wine(string arg)
{
        if( arg != "wine") return 0;
        if (!in_use)
       {  
        in_use =1;
        
	set("prevent_drop",1); 
        set_short("��ʹ֮��������Ч����"); 

	write( 
"��������Ɑ��ʹ֮�ǣ�һ���Ҹ����ֵĸо��������������������Լ������� \n"
	);
	tell_room( environment(this_player()), 
		this_player()->query("c_name")+"������һ����ʹ֮�ǣ�һȺ��ɫ����ʹΧ�����������ԡ�\n",
		this_player() );
 
	this_player()->set_temp("extra_db",20);
	call_out("restore",60,this_player());
	return 1;
        }
}

void restore(object player){

	tell_object(player, 
		"Χ���������Ե���ʹ�����ط�����...\n");
	this_player()->set_temp("extra_db",0);
        remove(); 
}
