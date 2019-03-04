#include "../saulin_temple.h"

inherit "/d/eastland/saulin_temple/monster/mob_special";

int be_released;

void create()
{
        ::create();
        set_level(18);
        set_name( "jay yeng", "��Զ��ʦ" );
        add ("id", ({ "monk","jay","yeng" }) );
        set_short("��Զ��ʦ");
        set("unit","λ");
        set_long(@C_LONG
����ǰ����λ����ɮ�˳���˹˹���ĵģ���������������������Ͱ��˵
���ϻ����������ִ������������ֵ�������Ȼ��ɽ�°�ˮ����ɽ�ϵ�
�����Ȼ������װ��ˮ�Ĵ���Ͱ����ɽ·��������ȴ����ƽ�أ����
�ڹ�����ʮ�ֵľ��ˡ���������һֱ����ʲ�ᾭ��ʲ��ģ��������
�Ը����ʸ������
C_LONG
        );
        set( "inquiry", ([
             "book" : ({ @BOOK
�����ӷ� ! ƶɮ���ǵ�ù ! �����ֵ�ƶɮֵ�زؾ���������һ
		λ������������ɮ�ͷ���ǰ����������̸�����������ĦԺ����
		���龭����һ����Ͼ���Ȼ��Ѱ��������Ͼ���Ȼ���ձ飬����
		�Ǳ��������Ǵ�Ħ����������Я���ģ�����ʵ�ڲ�ͬ���졣����
		���ˣ������ܷ������������������Ҳ��������£�����̫����
		��ȥ�ˡ���! �������ܻزؾ���(library) һ�ˣ�һ���ܲ��ʲ
		����˿����
BOOK
			}), "library" : ({@LIBRARY
���ˣ�����԰�ƶɮ��ȥ����𣿲ؾ����������ȳ�����ֻҪ��
              ���ȴ�ͬʱһ��(pull)�ͻ����һ��¥���ˣ�����԰��ҵ��ܸ�
              ���... ����... Ҫ�������ؾ����أ����������������ܣ�Ҫ
              ��ȥ����������(invisible) �ˣ�����������أ�����ƫƫ����
              ��͵������ȥ ... �� ����

��Զ��ʦ�ֿ�ʼ�������ҡҡͷ����������Ĵ��ڣ�����һ����������
����������Ͱ���ˡ�
LIBRARY
			}),
		]));

        set("alignment",1400);
        set("wealth/gold", 10);
        set("gender", "male");
        set("race", "human");
        set("chat_chance",10);
//	set("moving",1);
//	set("speed",25);
//	set("patrol",({"north","north","north","north","south",
//		"south","south","south",}));
        set_perm_stat("str", 25);
        set_perm_stat("dex", 28);
        set_perm_stat("int", 20);
        set("max_hp", 700);
        set("hit_points", 700);
        set("max_fp", 2000);
        set("force_points", 2000);
        set("special_defense", ([ "all" : 40, "none" : 50, "monk":20 ]) );
        set("aim_difficulty", ([ "critical" : 60, "vascular" : 60 ]) );
        set_natural_weapon( 25, 20, 40 );
        set_natural_armor( 70, 30 );
        set_skill("chain",100);
        set ("chat_output",({@C_LONG
��Զ˵������֪����˭͵�����Ǳ�㶼Ͼ�������Ҫ����������ˮ��ʡ��
C_LONG
        }));
        setenv("C_MIN", "$N����������ˮͰ���˹���" );
        setenv("C_MOUT", "$N����������ˮͰ��$D�뿪" );
	wield_weapon( SAULIN_OBJ"coul" );
        equip_armor( SAULIN_OBJ"cloth4" );
        equip_armor( SAULIN_OBJ"necklace" );
//	equip_armor( SAULIN_OBJ"armband1" );
 set("special_attack",(["damage_type" : "energy","main_damage" : 30,
                                "random_dam" : 20 , "hit_rate" : 25]));
        set( "tactic_func", "my_tactic" );
set("c_enemy_msg",
"\n��Զ��������Ͱ����ײ����������������һ�����죬���������ͷת�� ...\n\n");
set("c_room_msg","��Զ�����Ĵ�Ͱ����ײ������");
set("c_room_msg2", "�����ͷת�� ...\n");
}

void init()
{
    add_action( "do_release","release");
}

int do_release(string arg)
{
    if ( !arg || ((arg != "Jay yeng") && (arg!= "yeng") && (arg!= "jay yeng")))
    {
        tell_object(this_player(),"����Ҫ�ͷ�˭?\n");
        return 1;
    } 
    if ( this_player()->query_temp("book_quest/step") != 5 )
    {
        tell_object(this_player(),@MSG1
��Զ˵��ʩ�����ĺ���, ����������!
����, û�з��ɷ�ּ, ���Ĳ������롣
MSG1
);
        return 1;
    }
    if ( be_released == 1 )
    {
        tell_object(this_player(),
        "��! �����! �ո��Ѿ����˴������ɵķ�ּ�ˡ�Ī��������ƭ����?");
        return 1;
    }

    tell_object(this_player(),@MSG2
��Զ�м���˵������лʩ��, Ϊ����ϴ����׮ԩ����
                ��������ֿ����ٴμ�����Ρ���κ��о����г���
                ����! ˵���о�.....

�㿴����Զ�������߶�ʮһ�ؿ�ʼ������������, ���������������о���
MSG2
                );
    if (this_player()->query("force_effect") < 4) {
       tell_object(this_player(),
       "\n�����˾�Զ�Ļ�, ������������, �ƺ����ֵ�����ѧ���µ����.....\n\n");
       this_player()->set_temp("block_command",1);
       call_out("check_gonfus", 20, this_player());
                                                  }
     this_player()->add("alignment",1000);
     this_player()->set("book_quest_finish",1);
     be_released = 1;
     set("chat_chance",0);
     return 1;
}

void check_gonfus()
{
	object* eqs;
	int i;

       if (this_player()->query("monk_score") > 1800) {
       if (this_player()->query("force_effect") == 3) {
          tell_object(this_player(),@MSG3
��ȥ��ѧ������, ��������Ժ���������ư�����, �㡱��������һ����
������˾����񹦵�����, ���ȫ������Ѹ�ٵ������������ͨ, ѭ����
һʮ�˸���������, ���������˾����񹦣�
MSG3
);
          this_player()->set("force_effect",4);
          this_player()->set("force_points",this_player()->query("max_fp"));
                                                       }}
       else {
          tell_object(this_player(),@MSG4
���������㳤̾һ��, ��Զ�����ÿһ�仰, ������˵��̫�����,
��ʵ�����޷����, ����Ҫ��ȥ�úõ�����������
MSG4
);
            }
      tell_room(environment(this_player()),
          "\n�㿴����Զ�Թ��Ե��������дʣ�������Զ��! \n");
       this_player()->set_temp("block_command",0);
       eqs=all_inventory(this_object());
        this_object()->delete("weapon1");
        for ( i=sizeof(eqs)-1 ; i >-1 ; i--) {
                if (eqs[i]->query("equipped")) eqs[i]->delete("equipped");
                eqs[i]->remove();
        }
       remove();
}

