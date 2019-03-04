//#pragma save_binary

#include "/d/mage/mage.h"

inherit ROOM;

void create()
{
	object master;
	::create();
	set_short("The Magic Library", "ħ��ͼ���");
	set_long( @C_LONG_DESCRIPTION
������Ħ�Ǵ������ϵ�ħ��ͼ��ݣ���ʽ������ħ�������﷨�����ᱻ����
���ղ��ںü��������ĸ��˸ߵ����(bookrack)�ϣ�����Ŀǰ�ǹ�ħ��ʦ�������
�����е�ħ��֪ʶҲ�������ű�����ڼ����ղ����ڣ�����Ķ������ղ�Ԫ��ħ��
��ͼ���ң������Ǽ���ħ��֮��ɵľ����ң������ķ�����Ҫ���ռ�һЩ��Ƨ��ħ
���鼮�������һ��������ͨ����¥�ĸ߼�ħ����Դ�о��ҡ�
C_LONG_DESCRIPTION
	);

	set( "light", 1 );
	set( "no_monster", 1);
	set( "c_item_desc", ([ 
		"bookrack" : "ʮ���Ͼɵ�ľ��ܣ�����һЩ���Ƶľ���(scroll)���������ǻҳ���\n" ,
		"scroll" : "@@look_scroll"]) );
	set( "exits", ([ 
		"north" : MAGE"misc_lib", 
		"west"  : MAGE"black_lib", 
		"down"  : MAGE"mage_guild", 
		"east"  : MAGE"element_lib",
		"south" : MAGE"spell_lab",
		 "up"   : MAGE"energy_lab", 
    ]) );
	master = new( "/d/mage/tower/monsters/patolas");
	master->move( this_object() );
	reset();
}

string look_scroll()
{
	if (!present("patolas") ) return "һЩ���Ʋ�ȫ�ľ��ᣬ����дЩʲ���Ѿ��޷������ˡ�\n";
return(@DESC
һЩ���Ʋ�ȫ�ľ��ᣬ����дЩʲ���Ѿ��޷������ˡ�

������˹̾�˿�����˵�������ﱾ�����кܶ���ظߵȷ����ľ��ᣬ����
��һ�ι��ᱻ���֣�ħ�����ᱻ�Ӷ�һ�գ�ֻ������Щ���Ʋ����ľ��ᡣ
������Աȫħ������ĳ�Ա�������Ĵ����찵�ã���춲������һЩ����
�����䡣

	������[7] : �ؾ�����ŷ�𰲡���Ԫ��ħ���ȼ�50���Ϸ���ʹ�á�
	������[4] : ���ʦТ�⡣���ħ���ȼ�50���Ϸ���ʹ�á�
	��̫֮��[8] : �����������ħ���ȼ�50���Ϸ���ʹ�á�

����ĳ����֪����ԭ�����������ֹ���ħ��ֻ����һѧ֮��
   
	�ǿ�֮�� : ���˹���Ī����������������ħ���ȼ�50��̽�ն�60%
		���Ϸ���ʹ�á�
DESC
);
}

int clean_up() { return 0; }
