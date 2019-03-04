
#include "../echobomber.h"

inherit MONSTER;

void create()
{
	::create();
	set_level(18);
	seteuid(getuid());
	set_name( "Moorth Ranger Cisklyph", "Ĭ��˹���˺�ϣ˹������" );
	add ("id", ({"ranger", "cisklyph"}) );
	set_short( "a moorth ranger Cishlyph ", "Ĭ��˹���˺�ϣ˹������" );
	set_long(@DESC
һ����Ĭ��˹��½���˶��������˺�ϣ˹������, ����һ����Ŷ��յ���, ������
����ͨ�����˺�����, �����Ǹ�̽�ռ�, ��ѧ��. ����һ������������, ��������
֪ʶ���Ƿǳ���Ԩ��.
������ȴ��һ�����Այ���, ϲ���¶������о�. �¶�һ��˼������. �������Ѳ�
����,�鱾Ӧ��������õ����Ѱ�.
DESC
	);

    set("alignment",800 );
    set( "gender", "male" );
    set( "race", "human" );
    set( "unit", "��" );
	set_perm_stat( "dex", 28 );
	set_perm_stat( "str", 19 );
	set_perm_stat( "int", 29 );
	set_perm_stat( "con", 20 );
	set_perm_stat( "piety", 10);
	set_perm_stat( "karma", 30);
	set_skill("dodge",99);
	set ("max_hp", 890);
	set ("hit_points", 890);
	set ("wealth", ([ "gold": 30 ]) );
    set_natural_weapon( 44, 15, 45 );
	set_natural_armor( 88, 35 );
    set ("weight", 400);
    set("special_defense", (["all":30,"none":25]) );
    set("aim_difficulty",([ "critical":35,"weakest":30,"vascular":35 ]) );
    set( "inquiry", ([
         "muse" : "@@ask_muse",
         "annow": "@@ask_annow",
         "ruin" : "@@ask_ruin",
         "cart" : "@@ask_cart",
         "statue": "@@ask_statue",  
           ]) );
    
}

void ask_statue(object who)
{
     tell_object(who,@MSG1
��Щ�Զ����ǵĵ�����Ϊ���, ��Щ����ĵײ�����һ������Ķ�. ��
��ȴ�޷��˽⵽����������? ��Ҳ������һЩ������ȥ, ����ֻ����һ
Щ��ֵĻ���, �������ĵ���Ҳ����ֵĺ�..
MSG1
     );
     return;     

}

void ask_cart( object who )
{
     tell_object(who ,@MSG2
�Ե�, ��Щ�˿����ҽ����, �ҺͰ��˵ĳ��ϰ����Ǻ�����, ������������
���ǵĿ�Ӳɿ���ٶ�̫��, ��Ҫ�Ľ���ʱ��, �Ҿ��岻�ݴǵİ�����������
��ϵͳ��. 
MSG2
     );
}

void ask_ruin(object who)
{
    tell_object(who ,@MSG3
�����ż����Ѿ��о��ܾ���, ��������������ܷ����, ����һҹ֮��ȴ��а
��Ĵ�ħ��ʦ������������. �������, �����кܶ���Ҫ��������������, ��
������Ҫ�ľ�����˼Ȫ��֤ʵ. ��Щ�����˵�̽�ռ�����һ����, �����ƺ���
���ҵ�����˼Ȫ, �����ҷ��������е��鼮ȴ�޷��ҵ���ϸ�ļ���..........
���������ǵĵص��ƺ�����һЩ���صķ���, ������ʼ���޷��ҵ���ȷ��λ��
. ֻ֪�������ĸ�����ĵ����ƺ��ǹؼ�������..
MSG3
    );
}
void ask_muse( object who )
{
     object *items;
     int i;
     
     items=all_inventory(who);
     for(i=0;i<sizeof(items);i++) 
        if ( (string)items[i]->query("name")== "Black Box of Molader" ) 
           if (items[i]->query("quest_action/muse_filled")) {
           tell_object(who,@MSG4
�㷢������˼Ȫ��, �ܺ�, �������������˼Ȫ�Ĵ���.
��˵����˼Ȫ�����ܶ������\��\��. ������������׼�����.
������һ���ܴ�Ļ�����Ϯ�������, ����ʱ�������ô�����
ɫ����˼Ȫ����. һ��С�����ذ�Ȫˮ�����ڻ���, ˲����
Ϩ�����.
����......
�Բ�����̫������.��֮лл��֤ʵ����˼�Ĵ���.
MSG4
           );     
           who->set_explore("deathland#28");
           return;
           }
      tell_object( who, 
          "����㷢����˼Ȫ�Ļ�, ϣ�����ܴ�һЩȪˮ�������ҿ�.�һ�ܸм����.\n"
);
      return ;        
}

void ask_annow(object who)
{
      tell_object(who,"���峤��, һ���зḻ֪ʶ������.����õ�����.\n");
      return ;
}

