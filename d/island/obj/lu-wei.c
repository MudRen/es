#include <mudlib.h>
#include <stats.h>
#include <conditions.h>

#define SPOILED_TIME 500

inherit OBJECT;

void init()
{
	add_action( "eat_food", "eat" );
}

void create()
{
        
        seteuid(getuid());
	set_name("lu wei","����±ζ");
	add( "id" , ({ "lu","wei" }) );
   set_short("����±ζ");
   set_long(@LONG
���ſ�ջ����ʲ��±ζ��רΪ���¾��õ�С�ˡ�
LONG
	);
   	set("unit","��");
   	set("weight", 10);
   	set("value",({ 150, "silver" }) );
	call_out("be_spoiled", SPOILED_TIME );
	set("spoiled",0);
}

int eat_food(string arg)
{
        
	if( !arg ||( arg != "liu wei" && arg !="lu" && arg!= "wei") ) return 0;
	if( query("spoiled") )
	 {
		write(@LONG
		
��!����ˡ����������������Ѿ�����ȥ�ˣ�����ӹֵֹģ����������ˡ�

LONG
     );	
        SICK->apply_effect(this_player(),5,10,5);    
     	tell_room( environment(this_player()),this_player()->query("c_name")+"����һ��±ζ����ɫ�ֵֹģ�������±ζ����...\n", this_player());
		}
	        else {
		write( "��Ȼ�������鴫��±ζ��Ҫ���ܺ�Щ�ƾ͸�����...:)\n" );
		tell_room( environment(this_player()), 
		this_player()->query("c_name")+"�Ŵ��˿ڣ������¾Ͱ�±ζ�����ˡ�\n" , this_player());
		this_player()->receive_healing( 20+random(20) );
	}
	remove();
	return 1;
}

void be_spoiled()
{
	object owner;
	owner = environment(this_object());
	set ("value", ({ 1, "silver" }));
	set_short("����±ζ(����)");
	set_long(@LONG
���ſ�ջ����ʲ��±ζ��רΪ���¾��õ�С�ˡ�(�Ѿ����ˣ���֪���ܲ��ܳ�)	
LONG
      );
	set("spoiled",1);
	tell_object( owner,"�����й���ζ����������Ӵ���������?\n" );
}



