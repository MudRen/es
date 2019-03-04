#include "../moyada.h"

inherit WEAPON;

void create()
{
	set_name("Shovel", "����");
	add ("id",({ "shovel" }) );
	set_short("С����");
	set_long(
            "һ��С���ӣ�����������(dig)��\n"
	);
	set( "weapon_class", 10 );
        set( "type", "dagger" );
	set( "min_damage", 2 );
	set( "max_damage", 5 );
	set( "weight", 20 );
	set( "value", ({ 10, "silver" }) );
	set( "unit", "��" );
}

void init()
{
        add_action("to_dig","dig");
}

int to_dig(string str)
{
        object obj1, obj2;
        
        if ( !str || str=="" )
          write("��Ҫ���� ?\n");
        else {
          obj1=environment(this_object());
          if (living(obj1)) {
            obj2 = environment(obj1);
            if ((int)obj2->query("dig")==1) 
              obj2->to_find_dig(str);
            else
              write("���ﲻ���ڣ�\n");
          }
          else return notify_fail("�����ϲ�û�й��ߡ�\n");  
        }
        return 1;
}
