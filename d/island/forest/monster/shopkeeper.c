#include "../tsunami.h"

inherit HOME+"magic";
inherit MONSTER;

void create()
{
    ::create();
    set_level(5);
    set_name("Shopkeeper","Ǯ�ϰ�");
    add("id",({"keeper"}) );
    set_short("Ǯ�ϰ�");
    set_long(@LONG
Ǯ�ϰ���ΪԼĪ��ʮ��ͷ���������ӣ���߹���һ��С���ӣ�
������������ۣ�ʮ��ľ�������ģ������������Ƣ���е�Ź֣�
�⴫�����Ƿ���һʱ�Ĵ����������ò�Ҫ�����й�С͵(thief)
������Ŷ���������ŭ������ѽ�����۲�������һ����Ŷ�����ڶ�
ʱ�����������������е��˺�(scar)Ŷ���������·���ס�ģ�һ��
�޷��ӳ����Ļ��ۣ�
LONG
             );
    set("unit","��");
    set("gender","male");
    set("alignment",-500);
    set("race","daemon");
    set("no_attack",1);
    set("inquiry",([
          "thief":"@@ask_thief",
          "scar" :"@@ask_scar",
          ]) );
}
    
void ask_thief(object victim)
{
    write("Ǯ�ϰ�ͻȻ��ɫһ����һ��������ֻ��һ�ź�Ӱ������˹�������\n");
    tell_room( environment(victim),
    "\nͻȻһ������ֻ��һ����Ӱ��"+victim->query("c_name")+"���˹�����\n"
    , victim);
    kill_ob( victim);
    set_level(12);
    set_name("Great Thief","Ǯ�δ���");
    add("id",({"thief"}) );
    set_short("���  Ǯ�δ���");
    set_long(@LONG
    ԭ��Ǯ�ϰ�����Ƿ���һʱ�����ִ������ֻ����ȫ��װ��һ��
�����ܻ���ģ����
LONG
            );
    set("no_attack",0);
    set("c_killer_msg","\nͻȻһ������ֻ��һ����Ӱ�������˹�����\n");
    set("killer",1);
    set("tactic_func","my_tactic");
    
    set("chat_chance",20);
    set("att_chat_out",({
        "��С�ӣ����ҵ������������֪���Ĺ�ȥ���Ҹ�������壡��\n"
        }) );
    set_natural_weapon(18,13,17);
    set_natural_armor(35,15);
} 

int my_tactic()
{
    object victim;
    
    if( !(victim=query_attacker()) ) return 0;
    if( random(20) < 2){
      tell_object(victim,
      "����˳��һ�ӣ���ö�����������˹��������������ס��.......\n"
      "�ۡ���������ö���Ү������������\n"
                 );
       tell_room( environment(victim),
       "����͵͵���� "+victim->query("c_name")+" �Ű�������������ס�ˣ�\n"
       ,victim );
       victim->add("wealth/gold",5);
       return 1;
        }
     else if( random(20) < 5){
       tell_object(victim,
       "ͻȻ�������ݡ�����������������������������������ϣ��ۣ���ʹ����\n");
       tell_room( environment(victim),
       "����˳��һ������������������ȫ���� "
       +victim->query("c_name")+" ���ϣ�\n"
       ,victim );
       victim->receive_special_damage("evil",15);
       report( this_object(),victim );
       return 1;
      }
     else return 0;
} 

void ask_scar()
{
    int jus;
    jus = (int)this_player()->query("justice");
    if(!jus) write("Ǯ�ƹ�ָ�����Ц������ȫ��ǬǬ������, һ���˺�Ҳû��, ������������?????\n");
    else write("Ǯ�ƹ����ֳ���˵����!!����ȫ�����²�����С�˺�"+jus+"��, ����������Ҳ!!\n");
    return 1;
}    
    
