#include "../../story.h"

inherit MONSTER;
#define MAX_HP(x)   (int)x->query("max_hp")
#define HP(x)       (int)x->query("hit_points")
#define NAME(x)     (string)x->query("name")
#define CNAME(x)    (string)x->query("c_name");
void create()
{
    ::create();
    set_level(17);
    set_name( "Wizard Doctor", "�׹�" );
    add( "id",({"doctor","wizard"}) );
    set_short( "ҩʦ �׹�");
    set_long(@LONG
����ǰ��������һλ��Ŀ����Ͱ����׵���̫�š��׹��ǳ���ҽ��������Ĵ��
���������������β������в��Ҳ�������ҽ���Ʒ�����Ȼ���߲�̫���ϵ������Ч
֮��ȴ��������֮�⡣�׹��������������������β�����Ȼ�������࣬��ȴ˿��
û���κ�ƣ������ӣ������ĺ�������������κεط�������������Ҫ������
�㿴��(diagnose)��
LONG
            );
    set("unit","λ");
    set("race","��ʦ");
    set("age",79);
    set("gender","female" );
    set("alignment",800);
    set("weight",600);
    set("wealth/gold",70);
    set_temp("be_joke",2);
    set_perm_stat("str",19);
    set_perm_stat("dex",27);
    set_perm_stat("kar",30);
    set_perm_stat("int",28);
    set_perm_stat("pie",23);
    set("hit_points",600);
    set("max_hp",600);
    set("max_fp",400);
    set_natural_armor(12,39);
    set_natural_weapon(52,8,17);
    set_skill("dagger",90);
    set_skill( "bandage",90);
    set_skill("anatomlogy",100);
    set_skill("dodge",75);
    set_skill("parry",75);
    set("special_defense", ([ 
       "all": 200,"none":40,"energy":20]) );
    set("aim_difficulty",
    (["critical":50,"vascular":70,"ganglion":70,"weakest":30]) );
    set("stun_difficulty",90);
    wield_weapon(SWWEA"wiz_dagger1");
    equip_armor(SWARM"wiz_cloth2");
    equip_armor(SWARM"wiz_gloves1");
    equip_armor(SWARM"wiz_helmet2");
    set( "tactic_func", "my_tactic" );
    set( "inquiry", ([
          "lucky":"@@ask_dog",
       "diagnose":"@@ask_diagnose",
              "1":"@@ask_clot",
           "clot":"@@ask_clot",
           "ֹѪ":"@@ask_clot",
              "2":"@@ask_poison",
       "depoison":"@@ask_poison",
           "����":"@@ask_poison",
              "3":"@@ask_bandage",
        "bandage":"@@ask_bandage",
           "����":"@@ask_bandage",
      "disappear":"@@ask_disappear",   
              "4":"@@ask_disappear",
    ]) );
}        
void ask_dog(object asker)
{
write(@LONG
�׹�˵����lucky?Ī�����ʵĻ���ʦ��Ů����С�׹����������㣬ǰ���컹��
����������������ȥ�ﹷ��
LONG
   );
}
int hate()
{
   if ( this_player()->query_attacker() ) {
      write("\n�׹�������˵���ߣ��޳�С������Ȼ�� Pk �Ҿ�����Ҫ�����㿴����\n\n");
      return 1;
   }         
   return 0;
}
int ask_diagnose( object asker )
{
   if ( hate() ) return 1;
   command(sprintf("look %s",NAME(asker)));
   write(@LONG

�׹ÿ��Լ���Ȼ��˵����Ҫ�������ԣ��������븶Щ���á�����
�������������������������ҵĹ����۸�
    
          *****************************************************
          **			                	     **
          **   1.ֹѪ(clot)           :  15   GOLD (��) ��   **
          **   2.����(depoison)       :  25   GOLD (��) ��   **
          **   3.����(bandage)        :  6    GOLD (��) ��   **
          **   4.������ɢ(disappear)  :  100  GOLD (��) ��   **
          ** 				                     **
          *****************************************************

��֪��Ҫ��һ����
LONG
   );
}

void ask_bandage( object asker )
{
     if ( hate() ) return ;
     command(sprintf("look %s",NAME(asker)));

     if ( !asker->debit("gold",6) ) { 
        write("�׹�˵�����Բ�����Ǯ����������һ����Ҫ 6 GOLD��\n");
        return;
     }  
     if ( HP(asker)>MAX_HP(asker) ) { 
        write("�׹�˵�����ú��ӣ���úõ���\n");
        return ;
     }
     if ( asker->query_temp("bandaged") ) { 
        write("�׹�˵�����ú��ӣ����ƺ������˰�������Ӵ��\n");
        return ;
     }
     if ( !present("bandage",this_object()) ) {
        write("�׹�˵�������������ϵ�һЩ�����Ѿ��ù��ˣ�����Ը���һЩ��\n");
        return ;
     }
     command(sprintf("bandage %s",NAME(asker)) );
     write("�׹�˵�����ţ��������ˣ���һ�¿��˿ڴ��Ƿ��׵���\n");
     command(sprintf("pat %s",NAME(asker)));
     return ;
}
void ask_poison( object asker )
{
     if ( hate() ) return ;
     command(sprintf("look %s",NAME(asker)));
          
     if ( !asker->debit("gold",25) ) {
        write("�׹�˵�����Բ�����Ǯ����������һ����Ҫ 25 GOLD��\n");
        return;
     }
     if ( !asker->query("conditions/simple_poison") ) {
        write("�׹�˵�����ú��ӣ������ϲ�û���κ��ж��ļ���\n");
        return ;
     }
     write(@LONG

�׹��ý��������ж��Ĳ�λһ�̣�������������ĺ�Ѫ��
����Ѫ�������ֺ�ɫʱ���׹ó�����Ļ��������˲
�䣬����˿������ˣ�ֻ����һ��СС�İ̺ۣ�

�׹�˵�����ú��ӣ������еĶ�ҵ������ˡ�
LONG
    );   
    asker->delete("conditions/simple_poison");
    command(sprintf("pat %s",NAME(asker)));
    return ;    
}
void ask_clot( object asker )
{
     if ( hate() ) return ;
        command(sprintf("look %s",NAME(asker)));
          
     if ( !asker->debit("gold",15) ) {
        write("�׹�˵�����Բ�����Ǯ������ֹѪһ����Ҫ 15 GOLD��\n");
        return;
     }
     if ( !asker->query("conditions/bleeding") ) {
        write("�׹�˵�����ú��ӣ������ϲ�û����Ѫ�㡣\n");
        return ;
     }
     write(@LONG

�׹��������еĽ���������˿ڴ����˼��룬Ȼ��
�������˿ڴ������˲�䣬����Ҳ����Ѫ����
����ֻ����һ��СС�İ̺ۡ�

�׹�˵�����ţ����ˣ��Ѿ������Ѫ�ˡ�     

LONG
     );     
     command(sprintf("pat %s",NAME(asker)));
     asker->delete("conditions/bleeding");
     return ;     
}
void ask_disappear( object asker )
{
     object damn;
     if ( hate() ) return ;
     command(sprintf("look %s",NAME(asker)));
             
     if ( !asker->debit("gold",100) ) {
        write("�׹�˵�����Բ�����������Ǯ��������ɢһ����Ҫ 100 GOLD��\n");
        return;
     }
     damn=present("evil damn",asker);
     if ( !damn ) {
        write("�׹�˵�����ú��ӣ��㲢û�б������������\n");
        return ;
     }
     damn->remove();
     write(@LONG
                                                                      
ֻ���׹�һ�������赸�����������дʣ���������һ�� ...

�������ã��׹���������˵�����ţ�����Ҳû�б�а�鸽���ˣ�

LONG
     );
}
int my_tactic()
{
     object victim;
     int select;     
     
     if (!(victim= query_attacker())) return 0;
     if ( victim->query("conditions/herb_apply") ) { 
        victim->delete("conditions/herb_apply");
        set("conditions/herb_apply",({ 10, 7, 30 }));
     }
     switch( random(20) ) {
     case 0..8 : set("aiming_loc","critical");
                 break;
     case 9..10: set("aiming_loc","ganglion");
                 break;
     case 11..17:
                 if ( victim->query("conditions/bleeding") ) 
                     set("aiming_loc","weakest");
                 else set("aiming_loc","vascular");
                 break;
     default:
            set("aiming_loc","vascular");
            break;
     }                                             
     return 0;          
}                  