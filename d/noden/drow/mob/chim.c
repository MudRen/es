#include "../iigima.h"
#include <stats.h>

#include <conditions.h>
inherit MONSTER ;

void create ()
{

        ::create();
        set_level(14);
        set_name( "Evil mage Chim","а��ʦ��ķ" );
        add ("id", ({ "drow","mage","chim" }) );
        set_short( "Evil mage Chim","а��ʦ��ķ" );
        set("unit","λ");
        set("alignment",100);
        set("weight",500);
        set("wealth/copper",3800);
        set_long(
@C_LONG
������С���������ձ�����������о�������ܿ��������Ǻڰ�����
���а��ʦ��Ҳ���ϴ峤�İ��ܣ������ʱ�����������ķ����õ������
���������ͷ��������ͷ�����Ǽ�Ʒ����Ȼ��Ϊа��ʦ��������ȴ��
�������(help)�ˡ�
C_LONG
        );
        set_skill( "dodge", 70 );
        set_skill( "dagger", 70 );
        set_skill( "anatomlogy", 67 );
        set("defense_type","dodge");
        set( "aim_difficulty",([ "vascular":30,"weakest":30,"critical":30 ]) );
        set( "aiming_loc", "vascular" );
        set( "special_defense", ([
                "all":30, "fire":-10, "cold":-10, "evil":60, "divine":-30 ]) );
        set_perm_stat("int", 22);
        set_perm_stat("kar",19);
        set("max_hp",500);
        set("hit_points",500);
        set_natural_weapon(20,10,20);
        set_natural_armor(50,5);
        set ("race", "drow");
        set ("gender", "male");
        set( "tactic_func", "emit_confuse" );
        set_c_limbs(({"����","�Ų�","�ֱ�"}));
        set( "inquiry", ([
                "help" : ({
"��ѽѽ��������, ��Ҫ������? �Һ����������, ������ֻ��������Ү��\n"
"��������ڽ���֮����������(snake)��? �����Σ��Ŷ, ����....\n"
                  }),
                "snake" : ({
"�ţ�����������鱾�Ͽ�����ĳ���ߵ��۾��ܷ���(light)����������õ����ӡ�\n"
                   }),
                "light" : ({
"��ϸ��������Ҳ��֪�����������ǽ�������֮ʯ(stone)�ɣ�\n"
                  }),
                "stone" : ({
"��˵����ʯ����˾�ȿ�Ů�������������ﲻ׼������������Ҳû����..\n"
                  })
                        ]) );
        wield_weapon(OBJ"scale_dagger");
        equip_armor(ARM"robe");
        equip_armor(ARM"lucky_headband.c");
}
int accept_item(object me, object item)
{
   string name;
   object ob;

   name=(string)item->query("name");
   if (!name || (name!="stone of snake's eye"))
     return 1;
write("��ķ˵�����...��������ʯҮ���ã��Ұ��㽫������Ư���Ľ�ָ�ɡ�\n");
write("�㿴��ķ���������ô��ģ�Ū�˺�һ���....\n");
   if (!this_object()->query("ring")) {
     write("��ķ˵�������ˣ����ָ������Ϊ����ʯ֮��ɣ��������㡣\n");
     ob=new(ARM"ring");
     ob->move(this_player());
     set("ring",8);
   }
   else
  write("��ķ˵�����Բ���Ŷ���ҵĻ������ˣ���������ָ��\n");
   return 1;
}
int emit_confuse()
{
        object victim;
   if( random(10)>2 ||!(victim= query_attacker())) return 0;
            tell_room( environment(this_object()),
                    "��ķ�ӿڴ��ó�һ��ë���޵�̺����������һ��!!\n",
                        this_object() );
            (CONDITION_PREFIX + "confused")->apply_effect( victim, 6, 10 );
        return 1;
}

