
#include "/d/eastland/goomay/goomay.h"

inherit MONSTER ;

void create ()
{
        ::create();
        set_level(18);
        set_name( "Master of blacksmith", "��®���ˣ�����" );
        add ("id",({ "blacksmith","master"}));
        set_short( "��®���ˣ�����");
        set("unit","λ");
        set_long(
@C_LONG
�������е������µ�һ����ʦ�Ľ�®���˶������μ������Ѿ��м��������
ʷ�ˣ����ж�������ܳ��ģ���˵������ұ�������ı���һ�����⣬��ӵ��
��ħ��ע�������е����������������ֶ�����������Է�����Խһ��������
�������������������������Ѿ��������Զ����ˣ���ר��춵��ӵ�ѵ������
�Խ�®�Ķ��켼����Ȼ�ھ�������
C_LONG
);
        set ("gender", "male");
        set ("race", "dwarf");
        set_natural_armor( 90, 20 );
	set_natural_weapon(25,5,15 );
        set_perm_stat( "str", 30 );
        set_perm_stat( "kar", 25 );
        set_perm_stat( "int", 25 );
        set_perm_stat( "dex", 30 );
        set_skill( "longblade", 100 );
        set_skill( "parry", 100 );
	set("hit_points",1200);
	set("max_hp",1200);
        set( "special_defense", ([ "all": 40 ]) );
	set( "wealth/gold",100);
        wield_weapon( Obj"love_sword" );
        equip_armor( Obj"lovekey" );
        set( "inquiry", ([
                "fire"  : "@@ask_fire",
		"weapon" : "@@ask_weapon",
		"key" : "@@ask_key", 
        ]) );

}
int ask_key()
{
   tell_object(this_player(),
@ASK_KEY
����˵�����и���ס���Ű����ţ����������룮������������������
��֪���ҵ�����������һֱ������һ�����������ķ�ӡ��Ҳ������
�а���������Ե��������ȥ���ʿ�����Ӧ�û���������๤��
ASK_KEY
);
}
int ask_weapon()
{
        object me ;
        me=this_player();
        if( (int)this_player()->query_quest_level("Goddess_statue") > 1 ){
                tell_object(me,
                "����Ц���������� !! ����Ը����ʱΪ��Ч�ͣ�������Ҫ�����ʵ��Ĳ��ϰ� !!��\n"
			    );
                return 1;
	}
        else
        {
                tell_object(me,
                "����̾�����������������鰡��¯��û�� !!��\n");
		return 1;
	}
}

int receive_metal()
{
   object ob;
 if (this_player()->query_temp("get_magnetite")){
      tell_object(this_player(),
@METAL
��������������˿������ţ����ȷ�����Ǽ�������ħ����������
������Ȼ�����ػص������������̫��л���ˣ����ó�һЩ����������
��л��ɣ�
  ˵�꣬������ת��ص���¯�߿�ʼ����
METAL
);
   call_out("make_weapon",3,this_player());
}else{
	tell_object(this_player(),
@NOGET
�������˿���֮��˵�����ֲ��Ǵ������˵�Ӣ�ۣ���������лл��Ѵ���
���ͻ�����
NOGET
);
}
}
int receive_cloth()
{
        object ob ;
	tell_object(this_player(),
@CLOTH
��������ؽӹ��Ʋ�Ƭ��Ȼ����ϸ�ض�����������̾��һ����������ԭ��
��� !! �ѹ��в�׼�ƶ�¯�ӵ���ѵ���һ���Ϊֻ�����Ŷ��ѣ���������
���ǻ���ת�ε�ʱ���ˣ�������ذ������æ������԰�¯��(furnace)
�ƿ����� ..
CLOTH
	);
}

int ask_fire()
{
	object me ;
	me=this_player();
        if( (int)this_player()->query_quest_level("Goddess_statue") > 1 ){
		tell_object(me,
		"����Ц��������л���˵Ĺ��� !! ���ڵ�¯�����������\n");
		return 1;
	}
	else
	{
                tell_object(me,
@FIRE
����̾�������� !! û�뵽�����¾�Ȼ�����������ϣ���һֱ��Ϊ��ֻ�Ǹ�
��˵����������Ҹ������ˣ��ҵ�¯������������⣬¯������Ҳ��������
�����ϵĴ�˵˵���ǻ���������ȡ�û������ϵĻ�֮���Ϳ���ʹ¯����
ȼ�����������Ķ�ȥ�һ����أ�����һ��������Ҫ�ϣ��� !! ������®����
��Ҫɨ���ˡ�
FIRE
			    );
	return 1;
	}
}
int fix_symbol(object me)
{
	object ob;
	tell_object(me,"����վ������������һ���������Ķ��������������Ц�ݡ�\n");
	ob = new(Obj"royal_mark");
	ob->move(this_object());
	command("give mark to "+me->query("name"));
	command("smile "+me->query("name"));
	return 1;
}
int make_weapon(object hero)
{
        object ob;
        tell_object(hero,"����վ������������һ��ͨ�����׵�ذ�ף��������˹�����\n");
        ob = new("/d/eastland/goomay_mine/obj/dagger.c");
	ob->move(this_object());
	command("give dagger to "+hero->query("name"));
	command("smile "+hero->query("name"));
	return 1;
}
int accept_item(object me,object item)
{
	string name;

	name = (string) item->query("name") ;
	
	if ( name !="fire element" && name !="broken cloth" 
		&& name !="broken symbol"  ||
	 (int)this_player()->query_quest_level("Goddess_statue") > 2 ) {
	   if (name== "magic magnetite"){
	   item->remove();
   receive_metal();
	   return 1;
	       }
        tell_object(me,
	"����ҡҡͷ����лл !! �Ҳ���Ҫ�ⶫ�� !!��\n");

        command("give "+(string)item->query("name")+" to "+lower_case((string)me->query("name")));
        return 1;
	}
	if ( name=="broken cloth")
	{
	item->remove();
	receive_cloth();
	return 1;
	}
	if ( name == "broken symbol" ) {
	 if ((int)this_player()->query_quest_level("Goddess_statue") != 2 ) {
		tell_object(me,
			    "����ҡҡͷ����лл !! �Ҳ���Ҫ�ⶫ�� !!��\n");
		command("give "+(string)item->query("name")+" to "+lower_case((string)me->query("name")));
		return 1;
	 }
		item->remove();

		tell_object(me,@SYMBOL
�����ѽ�鷭����ȥ�Ŀ������ϵ������Ȼ��ת����ȥ��һ��С����
ǰ������������ʼר�ĵĹ�����
SYMBOL
		);
		call_out("fix_symbol",5,me);
		return 1;
	}
       if ((int)this_player()->query_quest_level("Goddess_statue") != 1 ) {
     tell_object(me,
        "����ҡҡͷ����лл !! �Ҳ���Ҫ�ⶫ�� !!��\n");

        command("give element to "+(string)me->query("name"));
        return 1;
	  }

     tell_object(me,
@MISSION
�������˵ı�ס���Ц������лл�� !! �������ҶμҵĶ��ˣ���®�ֿ���
���������ˣ�������ʲ����Ҫ�Ҷ����ĵط������㾡�ܷԸ� !!��
�����ֵ������ҵ���λ�����䶷�����ѣ�����ͨ���ֲ����ļ��ɣ������ȥ
����������
������֮������¯�У�˲ʱ¯��ת�࣬���е�������������������ʼŬ����
����һʱ֮�䣬�����Ķ����������һƬ��

MISSION
		);
	tell_object(me,set_color(
			"���Ⱦ�������ǵĿ��֣����þ���Ϊ֮һˬ ! [��õ� 3000 �㾭��]\n","HIY")
		    );
                item->remove();
	me->finish_quest("Goddess_statue",2);
	me->gain_experience( 3000 );

        return 1;
}
