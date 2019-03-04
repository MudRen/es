#include "../echobomber.h"

inherit WEAPON;

void create()
{
    seteuid(getuid());
	set_name("Pick", "ʮ�ָ�");
	add ("id",({ "pick" }) );
	set_short("a dwarven pick", "���˵�ʮ�ָ�");
	set_long(
            "һ�Ѱ��˵�ʮ�ָ䣬����������(excavate)\��\���ھ�(dig)��\n"
	);
	set( "unit", "ֻ" );
	set( "weapon_class", 7 );
	set( "type", "thrusting" );
	set( "min_damage", 5 );
	set( "max_damage", 18 );
	set( "weight", 120 );
	set( "value", ({ 460, "silver" }) );
}

void init()
{
        add_action("to_excavate","excavate");
        add_action("to_excavate","dig");
}

int to_excavate(string str)
{
        object obj1, obj2;
        
          if ( !str || str=="" )
           return notify_fail("������ʲ�ᶫ��?\n"); 
          obj1=environment(this_object());
          if (living(obj1)) {
            obj2 = environment(obj1);
            if (!( obj2->query("direction") )) 
               return notify_fail("�ƻ������ǲ��õ���Ϊ.\n");
            
            if ((string)obj2->query("direction")=="block" ) 
              obj2->to_find_excavate(str);
             // write ("���������ھ�ʱ,һֻ���µĹ����������,\n");
            else
              return notify_fail( 
                "��������ǰ��˵ĵ���,�㲻�������￪�䣡\n");
            }
          else return notify_fail( 
            "�����ϲ�û�й��ߡ�\n");  
        return 1;
}
