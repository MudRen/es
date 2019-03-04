#include <../zeus.h>

inherit MONSTER;

void create()
{       int wine; 
	object ob1, ob2;

	::create();
	set_level(20);
	set_name( "steely troll", "��������" );
	add( "id", ({ "troll" }) );
	set_short( "a steely troll", "��������" );
	set_long(@LONG
���ݷ𿴼�һ��ɽ����������ǰ������ȫ�����˸ּף����Ƕμ��ص�
Ƹ�����ش����ҵģ�����������������ѧ�䣬�ó������ƣ�Ŀǰû����
֪������ȱ�㣮��������������������˶���һ�ֵ��ӵ��۹⣬���μ�
����Ҳ�����⣬�����ƺ���̫Ѱ�����������ʿ��ɣ�
LONG
);
	set_perm_stat( "str", 30 );
	set_perm_stat( "dex", 30 );
	set_perm_stat( "kar", 30 );
	set_perm_stat( "int", 30 );
	set_skill( "unarmed", 100);
	set_skill( "parry", 100);     
	set_natural_armor( 120, 60 );
	set_natural_weapon( 70, 30, 70 );
	set( "time_to_heal", 6 );
          set("attack_skill","monk/general/bolo_fist");
          set("monk_gonfu/bolo-fist",25);
	set( "max_hp", 1500 );
	set( "max_fp",600);
	set( "force_effect",2);
	set( "force_points",600);
	set( "hit_points", 1500 );
	set( "gender", "male" );
	set( "alignment",-500 );
	set( "wealth/gold", 100 );
	set( "wine",0);
}  
int accept_item(object me,object item)
{       int wine; 
        if ((string)item->query("name")!="da chu"){
	tell_object(me,
	"���˵�����������𣿣������������Ҳ�ϲ���ⶫ���������»����ɣ�\n\n"
	"˵�����˾ͰѶ��������ˣ�\n",
	);
        command("drop all");
        return 1;
        }
        if(query("wine"))
        {
        tell_room(environment(this_object()),
        "��������������ˮ�㽫�Ƶ��������һ�����þƣ���\n"
        "Ȼ��Ų���\��\���ߵ��ӱߣ��ۣ�һ����������ȥ��\n\n"
        "�㿴��һ��ҩ��Ӿ��˵Ŀڴ��е�������������������ȥ�ˣ�\n\n"
                  );
        item->remove();
        set_short("���ľ���");
        set_name("troll","����ľ���");
        set_natural_armor(100,40);
        set("monk_gonfu/bolo-fist",20);
        return 1;
        }else{ 
        tell_room(environment(this_object()),
	"�������������޾���ˮ�㽫���еľ���Ǭ��Ȼ������������δ��\n\n"
	"��������û���أ�������Т�����ɣ�\n\n"
	);
	item->remove();
        set("wine",1);
      	return 1;
               }
}
void die()
{       object killer,obj;
        int wine;
 	if (query("wine")){
 	killer=query("last_attacker");
 	killer->set_temp("get_magnetite",1);
 	tell_room(environment(this_object()),
 	"��������ڵ����������Ĵ����Ұɣ����Ѿ�����Ҫ�Ķ������������ˣ�\n",
 	this_object());
 	set("exp_reward",36000);
 	::die(1);
 	}else{
 	tell_room(environment(this_object()),
 		"���˴�е������������𣿱�ɵ�˺��ӣ�\n"
 		"ͻȻ���˴ӿڴ���ץ��һ��ҩ��������һ����\n\n"
 		"��һ��������ĸ������ˣ�\n",
 		this_object());
 	set ("exp_reward",10); 
 	set ("alt_corpse",ZMOB"/iron_troll.c");
 	::die(1);
 	}
 	}