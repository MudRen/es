
#include "../echobomber.h"

inherit MONSTER;

string *rumors = ({ 
       "ҥ������ħ��ʦ���濭�����������Ļ�Ӱ���Ź����������ɽ���Ĵ��������� .\n",
       "ҥ��һ��Ư�������鱻���ڿ�ӵ��,�������Ѿ�Ѱ�����þ��� .\n",
       "��֪�����˴�ǰ���Թ���?�ƺ��и��ܴ�������������� .\n",
      // "��֪��ͨ��������½�ĵ������ͨ��������Ԩ�ĺ���֮���� ?\n",
                }); 

void create()
{
    object ob1;
	::create();
	set_level(11);
	set_name( "barkeeper", "�Ʊ�" );
	add("id",({"barkeeper"}));
	set_short( "a barkeeper", "�Ʊ�" );
	set_long(
		"A smiling barkeeper.\n",
		"һ������Ц���ľƱ� ,���Ѿ���������������.\n"
	    );
	set("alignment",440);
	set_perm_stat( "dex", 13 );
	set_perm_stat( "str", 10 );
	set_perm_stat( "int", 8 );
	set_perm_stat( "con", 10 );
	set_perm_stat( "piety", 12);
	set_perm_stat( "karma", 13);	
	set( "race", "dwarf" );
	set( "gender", "male" );
	set_natural_armor(56,20);
	set_natural_weapon(10,10,11);
	set_skill("dagger",50);
	set_skill("dodge" ,60);
	set( "inquiry", ([
		"legend" : "@@ask_rumor",
		"muse" : "@@ask_muse",
		"rumor" : "@@ask_rumor",
	]) );
	wield_weapon(Weapon"/dagger01");
	ob1=new(Object"/broom");
	ob1->move(this_object());
}


void ask_rumor(object who)
{
     int i;
     i=random(sizeof(rumors));
     tell_object(who,
          "��Ʊ�˵:"+ rumors[i]
          );
     return;   
}

void ask_muse(object who)
{
        tell_object(who,can_read_chinese()?
         "��˵�е���˼Ȫ?��,��,...\n":
         "Need Translation.\n"
                   );
        return;
} 

