#include <mudlib.h>
void create(object ob)
{
        if (!ob) return ;
        seteuid(getuid()) ;
	ob->set_level(3);
	ob->set_name( "big cat", "����è" );
	ob->add( "id", ({ "cat","big cat" }) );
	ob->set_short( "����è" );
	ob->set_long(
	 "�㿴��һֻ�޴����è�������ڽ��䡣\n"
	);
	ob->set( "unit", "ֻ" );
	ob->set( "alignment", -200 );
	ob->set_c_verbs( ({ "%s�ſ�������%s����һҧ" }) );
	ob->set_c_limbs( ({ "ͷ��", "����", "�Ȳ�" }) );
        ob->set("chat_chance",5) ;
        ob->set("att_chat_output",
          ({"����è˵:����ѽ! ץ�������󻹲���? �����㻹Ҫ�ҵ���!!\n",
            "����è˵:������ɱ��!! ��֪��������������� !!\n",
            "����è˵:������! ��͵Ц! ������ͻ���������!!\n"})) ;
}
