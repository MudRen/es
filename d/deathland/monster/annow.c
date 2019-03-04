#include "../echobomber.h"

inherit MONSTER;

void create ()
{
	::create();
	seteuid( getuid() );
    set_level(16);
    set_name("the older Annow","���峤��");
    add("id",({"older","annow"}) );
    set_short("the older Annow","���峤��");
	set_long(
@C_LONG
һ����ǵĳ���,�ƺ�������֪������.��˵����������ʱ��,���ҵ�������,���Ǽ�ʹ
�������Ļ�, ��Ҳֻ��ЦһЦ�����ش���
C_LONG
	);
    set("alignment",880);
    set( "gender", "male" );
    set( "race", "dwarf");
    set( "unit", "��" );
    set_perm_stat( "dex",19);
    set_perm_stat( "str",14);
    set_perm_stat( "int",26);
    set_perm_stat( "con",17);
    set_perm_stat( "piety",27);
    set_perm_stat( "karma",16);
	
    set ("max_hp",390);
    set ("hit_points",390);
    set ("wealth", ([ "gold":30]) );
    set_natural_weapon(33,15,30 );
	set_natural_armor( 65 ,30 );
    set ("weight", 350);
    
    set( "inquiry", ([
         "crystalball" : "@@ask_crystalball",
         "muse" : "@@ask_muse",
         "trouble":"@@ask_trouble",
         "chichikair":"@@ask_chichikair",
         "morr":"@@ask_morr",
         "ruin":"@@ask_ruin",
         "tower":"@@ask_tower",
         "queen":"@@ask_queen",
         "bell":"@@ask_bell",
         ]) );
    set("special_defense", (["all":33,"none":20]) ); 
    set ("aim_difficulty",(["vascular":20]) );
    set( "tactic_func", "cast_spell");
}

void ask_crystalball(object who)
{
     tell_object( who ,
       "����˵:�ǿ�ħ��ˮ����,���ṩ������Ʈ������Դ��.\n"
       "������Ҳ���Խ��������뿪����ط�.\n"
       );    
     return;  
}

void ask_cisklyph(object who)
{
     tell_object(who,
     "һ��ϲ��̽�յ����˺�, ��������һ��̽��а���Ѫ��, ����һ������\n"
     "�˳���, ������������֮�����õ�����. ϲ��ð�յ������ڴ���ڹŴ�\n"
     "�ż���Ѱ�����ܰ�.\n"
);
     return; 
}

void ask_muse(object who)
{
     
     tell_object(who,
                 "��˼Ȫ,ʫ������ĵط�,��˵�ܹ���������������.\n"
                 "��Ҳ��Ѱ���ܾ���.....\n"
                 "���ҵ�һ��������ϣ˹������(Cisklyph), Ϊ�������\n"
                 "��Ҳǰ����˵�еĹŴ�����(ruin)��.\n"
                 );
     return;
}
void ask_queen(object who)
{
     tell_object(who,"�����Ļʺ�, ȫ��������Ϊ�����ڵ�����\n");
}
void ask_trouble(object who)
{
     tell_object(who,
                 "����˵: ��һ���ܴ���鷳�����������ǵĴ�ׯ,����֪������µ��˲���.\n"
                 "һ�����İ���ħ��ʦ���濭��(chichikair),��֪�������﻽��һЩ��Ӱ \n"
                 "����,������Ϊ�ǳ����˲���,��Ȼ��Ҫ����������غ�ɫħ��������Ĵ���\n"
                 "������,�ƻ����������������ĺ�ƽ ,һȺ�����Ѿ���ͷʹ��,���ټ��ϸ�\n"
                 "��(tower)�����Ща��ħ��ʦ,�Ҳ�����������������....."
                 ); 
     return;            
}

void ask_chichikair(object who)
{
     tell_object(who,
                 "����˵: ���İ���ħ��ʦ���濭��,ԭ��Ҳ��һ�������ĺ���,�����Դ���\n"
                 "�Ĵ�С����һ�𳤴�ĺ��ѷ�������������,����������,�����о���а\n"
                 "��İ���ħ��,������ͬ��Ħ��֪���������,Ҳǧ����������������Ȱ����\n"
                 ",�������濭��ȴʧ����.Ħ��˵��������һ�����صĵط�,��ȷʵ�ĵص㲢��\n"
                 "����֪,ֻ�ܴ��֪���ڰ����Թ�������.��Ӧ�õ�ȥ���ҿ�\n"
                 );
     who->set_explore("deathland#29"); 
     return;            

}

void ask_morr(object who)
{
     tell_object(who,
                 "һ��Ů����ħ��ʦ,ħ����ǿ,ϲ�ð���������,���������Լ���ס����ħ���ϱ�\n"
                 "��������,�Ա������˵Ĵ���,��Ҫ������Ҫһ����������.\n"
                 );
}

void ask_ruin(object who)
{
     tell_object(who,
                 "�����Թ�������һ���ܴ������. ��˵�и����صĹŴ��ż������ĳ���ط�, \n"
                 "����û�м������ܹ���������λ��. \n"
                 "��˵�ܾ���ǰһ������̽�ռ�������������λ��, ������ȴ������˵�ս����\n"
                 "������..\n"
                 );
}
void ask_bell(object who)
{
     object *items;
     int i;
      
     items=all_inventory(who);
     for(i=0;i<sizeof(items);i++) {
        if ( (string)items[i]->query("name")== "Black Box of Molader" )
           if (items[i]->query("quest_item/explorer_bell"))
             {
             tell_object(who,
             "���忴��һ����ں��ӵ��嵱��˵:\n"
             "û��: �����ΰ��̽�ռҵ��嵱, �ǵ���������\��\��˵, ����嵱\n"
             "�ܹ�ָ���㵽��Ŵ��ż�ȥ. ֻҪ�Ҽ����ʵ�������Ϳ�������.\n"
             "������п�ʼ�����д�.....\n...\n..\n.......\n..\n.....\n.\n...\n"
             "................\n.\n....\n"
             "������������,������嵱�����㲢��˵:\n"
             "ȥ��! ����ó̲Ÿտ�ʼ.\n"
             );
             items[i]->set("quest_action/invoke_bell",1);
             who->set_explore("deathland#23");
             if ( (int)who->query_quest_level("queen_smile") < 1 )
               who->finish_quest("queen_smile",1);
             return;
             }
       }
     tell_object(who,
     "������ʲ���嵱??\n"
     );
     return;  
}

void ask_tower(object who)
{
     tell_object(who,
                 "��ɫħ������,�����ƺ��Ѿ��ܾ�û�����ᶯ����,��������\n"
                 "��ħ��ʵ���Ƿǳ��Ŀ���,�����Ǵ���������,һ��ʮ������\n"
                 "�Ĳ�������,��˵����а��Yang��Ψһ����,����ħ��û����\n"
                 ",Ӧ��˵��û�л���������������,���Ǹ�����һ�ȵ���˹��\n"
                 ",ֻ���������,�����������ǳ��뺣����.����,˭Ը��ȥ��\n"
                 "�����ħ����?\n"
);
}

int cast_spell()
{
    object victim;
    string name,c_name;
    if( !(victim = query_attacker()) ) return 0;
    
    name = victim->query("name");
    c_name= victim->query("c_name");
    
    if( random(10) < 6 ) {
      tell_room( environment(this_object()), 
        "\n\n������:����֮��........\n" );
      victim->receive_special_damage("fire", 14+random(6));
      return 0;
    }
    if( (this_object()->query("hit_points")<180) && (random(100)<50) ) {
      tell_room( environment(this_object()), 
        "����ʹ�����֮��ҽ�����Լ���\n" 
      );
      this_object()->receive_healing(35+random(30));
      return 1;
    }
    
    return 0;
}

