#include <../goomay.h>

inherit MONSTER;

int is_iced = 0;

void create()
{
	::create();
	set_level(13);

        set_name( "@@query_short", "@@query_c_chort" );
        add( "id", ({ "beast","spirit" }) );
        set_short( "@@query_c_short" );
        set("long", "@@query_c_long");

	set_perm_stat( "str", 15 );
	set_perm_stat( "int", 18 );
	set_perm_stat( "dex", 18 );
	set_perm_stat( "kar", 18 );
	set_skill( "dodge", 100 );
	set( "alignment", 500 );
	set( "natural_armor_class", 60 );
	set( "natural_defense_bonus", 20 );
	set( "natural_weapon_class1", 32 );
	set( "natural_min_damage1", 12 );
	set( "natural_max_damage1", 23 );
	set( "tactic_func", "my_tactic" );
	set( "chat_chance", 20 );
	set( "att_chat_output", ({
		"����ŭ��������ɶ� !! �����������ң�ȴ��Ҫɱ�� !!�� \n",
		"����ŭ����������㳢���һ�������� !! ��\n"
	}) );


}
string query_short()
{
	if ( !this_player() ) return "fire beast";
 if (this_player()->query_temp("fire_element"))
	return "fire spirit";
	return "fire beast";
}
string query_c_short()
{
	if ( !this_player() ) return "����" ;
 if (this_player()->query_temp("fire_element"))
        return "����";
        return "����";
}

string query_c_long()
{
	if ( ! this_player()) return "";
 if (this_player()->query_temp("fire_element"))
    return "��ֻ�����������ɫ�������ͷ�������Ķ�ͷ����һ�������ӡ�ǣ���\n"
              "������߽Ӵ��������۾�ʱ����Ц�ĺܿ��ġ�\n";

return "��ֻ�����������ɫ�������ͷ�������Ķ�ͷ����һ�������ӡ�ǣ���\n"
	"������߽Ӵ��������۾�ʱ�����������������ƽ�͡�\n";
}

int accept_item(object me,object item)
{
object ob,ob2;
     if ((string) item->query("name") !="crystal of ice" ) return 1;
     if (this_player()->query_temp("fire_element")) return 1;
     tell_object(me,
@MISSION
���������Ľӹ��������������ͻȻӿ��һ�󼤶���Ц�ݣ���������
���ɵĿ����㣬����ʼ����һ��Ц���£�������\ˮ�������������
�����ò���������˵�����������ϴ�û�����˽�����ǣ����ǲ���а
�����壬�ڼ��˵Ļ����³�����������Ҫ��ֻ�����еĹػ������㣬
�������������ʹ������ȥ���ԣ�ת���ӵ��ƽ��������������лл
��ĸ������˽⣬�ټ��� !! �ҵ����� !! ϣ����һ�컹���ټ����㡹

�����ѱ������������ؿڣ�ͻȻǿ�ҹ⻪���䣬���������𡹵�һ��
���죬������ʲ�ᶫ�����ڵ��ϣ�������˫��һ���������Ѿ�������
Ӱ�ˡ�
��Ķ�������һ���������޵�����һֱ�ظ���������.. ���� ..
MISSION
         );

                item->remove();
                ob = new( Obj"fire_element" );
                ob->move( environment(this_object()) );

		this_player()->set_temp("fire_element",1);
                if ((string)this_player()->query("class")=="scholar") {
                   tell_object(this_player(),"�������������������ߣ���Ҫ��æ��ʱ����CALL�ң���Ҫ������� !\n");
                   this_player()->set("demand/fire",2);
                }
                remove();
        return 1;
}

void report( object attacker, object victim )
{
   string c_message;
   seteuid(getuid());
   c_message= "/adm/daemons/statsd"->status_string(victim);
   tell_object( victim,"( ��"+c_message+" )\n");
}

int my_tactic()
{
	object *victim,ob;
	int i,spec;

	spec=random(100);
	if (spec <20 && (victim = query_attackers()))
	{
	tell_room( environment(this_object()), 
		"\n�������һ�����棬ɨ��������壬��е�һ������ !!\n\n" ,
		this_object() );
	for( i=0; i<sizeof(victim); i++ )
	    {
		victim[i]->receive_special_damage( "fire", 20+random(10) );
		report(this_object(),victim[i]);
	    }
		return 1;
	}
	else if ( spec>20 && spec<50 && (victim = query_attackers()) ) 
	{
        tell_room( environment(this_object()), 
                "\n����ɢ����ǿ�ҵĹ�â������۾�һ���ʹ !!\n\n" ,
                this_object() );
        for( i=0; i<sizeof(victim); i++ )
	{
        ob = present("glasses", victim[i]);
        if(ob && ob->query("equipped"))
	{
	tell_object( victim[i], 
		"���ī����ס�˴��۵�ǿ�⡣\n\n");
	}
	else
	{
        if( victim[i]->query("stop_attack") ) continue;
        victim[i]->block_attack(8);
        victim[i]->set_temp("msg_stop_attack", 
          "( ������ʲ��Ҳ������ ! )\n" );
	}
	}
	return 1;
	}
	return 0;
}

void iced()
{
	is_iced = 1;
	tell_room( environment(this_object()), 
	"����������У��� �����ļһ� ! ���Ǹ������ÿ� !��\n" ,
		this_object() );
}

void die()
{
	object ob;
	if( is_iced )
	{
		::die();
	}
	else {
		tell_room( environment(this_object()), 
			"�������һ�������ѳ���\��С���� ....\n\n"
			"������һ�����������ӻ����з���: ������Ϊ�����ͽ������𣿡�\n\n"
			"С���������¾���һ�𣬻����ִӻ���������\n\n" ,
			this_object() );
		set( "exp_reward", 1 );
		set( "alt_corpse", Mob"fire_beast" );
		::die(1);
	}
}
