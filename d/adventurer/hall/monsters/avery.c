#include "mudlib.h"
#include <daemons.h>
#define AIM ({ "ganglion","vascular","weakest"})

inherit "/d/adventurer/adv_trainer";
inherit MONSTER;

void init()
{
npc::init();
adv_trainer::init();
add_action("do_list","list");
}
void create ()
{
 //   int i;
 //   i = random(2);
	::create();
    set_level(19);
    set_name("Great Avery","��ð�ռ�  ������");
    add("id",({"avery","great","adventurer"}) );
    set_short("��ð�ռ�  ������");
	set_long(@C_LONG
    ��ð�ռ�  ����������Ĭ���������ĵ��ӣ�����������Ĭ���ϵ��洫��������ð
�յ������У�ѧ��������¼��ɡ������������Ĭ�������У��ڴ�ѵ����־��ð��Ϊ��
��ְҵ��ð���ߡ�
������������һ�ָ߰���м���۹�������㡣
C_LONG
	);
    set("alignment",1000);
    set( "gender", "male" );
    set( "race", "human");
    set( "unit", "��" );
    set_perm_stat( "dex",30);
    set_perm_stat( "str",28);
    set_perm_stat( "int",20);
    set_perm_stat( "karma",30);
    set_skill("whip",100);	
    set_skill("dodge",80);
    set_skill("parry",100);
    set_skill("anatomlogy",55);
    set ("max_hp",1300);
    set ("hit_points",1300);
    set( "chat_chance",12);  
    set("chat_output",({"��������������: ����Щ������İ���...\n"}));
    set ("wealth", ([ "gold":300]) );
    set_natural_weapon(35,22,34);
    set_natural_armor(70,40);
    set ("aim_difficulty",([ "weakest":50,"vascular":30]) );
    set("special_defense", (["fire":90,"none":20]) );
    set( "aiming_loc", "weakest" );
//    AIM[i] );
    set( "tactic","berserk" );
    set ("weight", 400);
    wield_weapon( "/d/adventurer/hall/weapons/avery_whip" );
    set("inquiry",([
        "train" : "@@ask_train",
        "polemic" : "@@ask_polemic", 
        "trading" : "@@ask_trading",
        "ethics" : "@@ask_ethics",
        "diagnose" : "@@ask_diagnose",
        "hang" : "@@ask_hang",
        "natural_history" : "@@ask_natural",
        "green-magic" : "@@ask_green"
        ]));
    set("tactic_func","special_attack");
    set_lessons( ([
	"polemic": ({ 120, 50, 10 }),
	"trading": ({ 150, 70, 10 }),
	"ethics": ({ 130, 50, 20 }),
	"diagnose": ({ 120, 60, 20 }),
	"hang": ({ 220, 90, 50 }),
        "natural_history": ({ 150, 100, 40 }),
        "target": ({ 200, 50, 70 }),
      "concentrate": ({ 200, 50, 70 }),
        "green-magic": ({ 200, 50, 70 }) 
	]) );
}
int special_attack()
{
        int i;
        if(random(10)<7) return 0;
        i = random(2) ;
        set( "aiming_loc", AIM[i] );
        return 1;
}        

void ask_natural()
{
   if ((string)this_player()->query("class") != "adventurer" ) {
       write("��ð�ռ�  ������˵��: �����Լ�����ȥ��...\n");
           return ;
   }
   
   write("��ð�ռ�  ������˵��: ����ѧ����������ʶһЩ��������Ȼ����\n"
         "���� explore ָ����Ұ��Ѱ�ҵ����ǡ�����Դ�help explore�õ�����\n"
         "����Ѷ��\n");
   return ;
}
void ask_train()
{  
     if ((string)this_player()->query("class") != "adventurer" ) {
     write("��ð�ռ�  ������˵��: �����Լ�����ȥ��...\n");
    return ; 
     }
     write("��ð�ռ�  ������˵��: û���ҿ��Խ�����һЩƽ��ѧ�����ļ��ܡ�\n"
           "��ǰ����ƽ��ð�ն�Ҫ���ߣ��������listָ������Ŀǰ����ѧʲ�ᡣ\n");                     
    return ;
}
void ask_polemic()
{  
    if ((string)this_player()->query("class") != "adventurer" ) {
    write("��ð�ռ�  ������˵��: �����Լ�����ȥ��...\n");
   return ;
    } 
    write("��ð�ռ�  ������˵��: ѧ��������㽫ӵ��˵�����˵����������ܵ��˹���ʱ\n"
    "Ҳ�������û�¸(bribe)ʹ����ֹͣ�����㣬��˵��һ�������ļ��ܡ�\n");
   return ;
}
void ask_trading()
{  
    if ((string)this_player()->query("class") != "adventurer" ) {
    write("��ð�ռ�  ������˵��: �����Լ�����ȥ��...\n");
    return ;
    }
    write("��ð�ռ�  ������˵��: ѧ�ύ�׼��ɣ���ʹ��������Ʒ�ļ��ɸ�Ϊ�߳�������\n"
    "���ᱻ������ƭ�������Դ��л��Ӧ�е����棬��˵��һ��׬Ǯ�ļ��ܡ�\n");
   return ;
}
void ask_ethics()
{  
    if((string)this_player()->query("class") != "adventurer" ) {
    write("��ð�ռ�  ������˵��: �����Լ�����ȥ��...\n");
    return ;
    }
    write("��ð�ռ�  ������˵��: ����ѧ��Ҫ�ڽ��������Ƿǣ�֪��ʲ���ǶԵģ�ʲ��\n"
    "�Ǵ�ģ������������ѧ���¹���Ļ����Ϳ��Դ�һ���˵����о�ֹ����������\n"
    "�ϳ�һ���˵��ƶ������������ʹ��consider ָ���ʱ����Զ�ʹ�á�\n");
   return ;
}
void ask_diagnose()
{  
    if((string)this_player()->query("class") != "adventurer" ) {
    write("��ð�ռ�  ������˵��: �����Լ�����ȥ��...\n");
    return ;
    }
    write("��ð�ռ�  ������˵��: �����������ܹ�ʹ��֪���Լ������˵�״̬\n"
    "�ڹ��������ʱ֪�����˵�״̬���ܹ�ʹ��Զ��Σ�ա�\n"); 
   return ;
}
void ask_hang()
{
    if((string)this_player()->query("class") != "adventurer" ) {
    write("��ð�ռ�  ������˵��: �����Լ�����ȥ��...\n");
    return ;
    }
    write("��ð�ռ�  ������˵��: ��ɱ��������ܹ�ʹ��ʹ�ó���������\n"
          "��ɱ���ˣ���ʩ���ɹ������˻���������ʱ�����ж���\n");
          return ;
    }
void ask_green()
{
    if((string)this_player()->query("class") != "adventurer" ) {
    write("��ð�ռ�  ������˵��: �����Լ�����ȥ��...\n");
    return ;
    }
    write("��ð�ռ�  ������˵��: ���ߵȼ���ð���ߣ�����ۻ�������\n"
          "�������ǻۣ���˾��л�������ħ�������������Ҳ�����������\n"
          "����Ҫ�Լ�ȥ���ֲ�ѧϰ�� ��\n");
    return ;
    }



int check_trainee(object trainee)
{
    if( (string)trainee->query("class")=="adventurer" && (int)trainee->query_level() > 4 )
    return 1;
    else
    return notify_fail(
    "��ð�ռ�  ������˵��: ��ֻ�̹��ʸ��ð���ߣ�����������ϣ�\n");
}
int do_list()
{
     int explore,total_points,EXPLORE1;
     explore  = (int)this_player()->query_explore_points();
     total_points=EXPLORE_D->query_total_explore(); 
     EXPLORE1=explore*10000/total_points;
     if (EXPLORE1 > 10000) EXPLORE1 =10000;
     if((string)this_player()->query("class") != "adventurer" ) {
     write("��ð�ռ�  ������˵��: �����Լ�����ȥ��...\n");
     return 0;
     }
     if ( EXPLORE1 < 1000 ) {
     write("������˵��: ����Ŀǰ���������������������ѧϰ�κμ���...\n");
     return 1;
     }
     write("������������ѵ���ļ�����:\n");
if ( EXPLORE1 > 6999 )
    write("\n    Ŀ��(target)                   ( ����ֵ���� = 200%, ���� =  50 )"
 "\n    ר��(concentrate)              ( ����ֵ���� = 200%, ���� =  50 )" 
"\n    ��ħ��(green-magic)            ( ����ֵ���� = 200%, ���� =  50 )");  
     if ( EXPLORE1 > 4999 )
     write("    ��ɱ(hang)                     ( ����ֵ���� = 220%, ���� =  90 )");
     if ( EXPLORE1 > 3999 )
     write("    ����ѧ(natural_history)        ( ����ֵ���� = 150%, ���� = 100 )");
     if ( EXPLORE1 > 1999 )
     write("    ���(diagnose)                 ( ����ֵ���� = 120%, ���� =  60 )"
           "    ����ѧ(ethics)                 ( ����ֵ���� = 130%, ���� =  50 )");
     if ( EXPLORE1 > 999 )
     write("    ����(trading)                  ( ����ֵ���� = 150%, ���� =  70 )"
           "    ����(polemic)                  ( ����ֵ���� = 120%, ���� =  50 )\n");
     return 1;
}    
