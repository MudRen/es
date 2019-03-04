#include "../moyada.h"

inherit WEAPON;

void create()
{
	set_name("Scythe", "����");
	add ("id",({ "scythe", }) );
	set_short("����");
	set_long(
	    "һ�Ѻܷ��������������������(cropp)��\n"
	);
	set( "unit", "��" );
	set( "weapon_class", 5 );
	set( "type", "shortblade" );
	set( "min_damage", 5 );
	set( "max_damage", 10 );
	set( "weight", 35 );
	set( "value", ({ 10, "silver" }) );
}

void init()
{
        add_action("to_cropp","cropp");
}

int to_cropp(string str)
{
        object obj1, obj2;
        
        if ( !str || str=="" )
          write("��Ҫ��ʲ�� ?\n");
        else {
          obj1=environment(this_object());
          if (living(obj1)) {
            obj2=environment(obj1);
            if ((int)obj2->query("cropp")==1) 
              obj2->to_find_cropp(str);
            else write("�㲻�ܸ�����\n");
          }
          else return notify_fail("�����ϲ�û�й��ߡ�\n");  
        }
        return 1;
}
