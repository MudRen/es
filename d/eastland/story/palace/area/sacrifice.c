#include <move.h>
#include <mudlib.h>
#include <money.h>

inherit ROOM;
inherit COINVALUE;
void create()
{
	::create();
	set_short( "����̨" );
	set_long( "�����Ƿ���̨��\n" );

}

void init()
{
	add_action("do_sacrifice", "sacrifice");
        add_action("do_sacrifice", "sac");
        add_action("do_sacrifice", "rebo");
}

void convert_value( object ob )
{
	mixed *value;
	int val;

	value = ob->query( "value" );
	if( !value || !pointerp(value) ) {
		ob->delete("value");
		return;
	}
	if( !intp(value[0]) || value[0]==0 || !stringp(value[1]) ) {
		ob->delete("value");
		return;
	}
	val = value[0] * coinvalue( value[1] ) / coinvalue("silver");
	if( val==0 ) val = 1;
	ob->set( "value", ({ val, "silver" }) );
	return;
}

int sell_ob(object ob)
{
	int will_remove, res, number;
	string type, unit;
	mixed *value ,*rate;

	convert_value(ob);
	value = ob->query("value");
	if( !value ) {
		tell_object(this_player(),sprintf(
		   "���˵��:��û�м�ֵ�Ķ���(%s)Ҳ�ҷ��׸��ң�û�����\n",
		   ob->query("short")));
		ob->remove();
		return 1;
	}
    number = value[0] ;
	if (!this_object()->query("rating"))
	  number = number * SHOP_SALES_FRAC;
	else {
	  rate = this_object()->query("rating");
	  number = number * rate[0] / rate[1];
	}
	number -= number * ( 75 - (int)this_player()->query_skill("trading") ) / 200;
	if(number>1000) number = 1000;

	type = value[1];
	ob->move(this_object());
	if( !(unit = ob->query("unit")) ) unit = "��";
	write(sprintf("������ϵ�%s���׸���ۣ�������Ĵ����͸��� %d ��%s��\n",
	    ob->query("short"),number,to_chinese(type+" coin")));
	tell_room( this_object(),sprintf("%s���׸����һ%s%s��\n",
		this_player()->query("c_name"),unit,ob->query("short")),
		this_player() );
        ob->remove();
	return 1;
}
int do_sacrifice(string str)
{
	int i;
	object ob, *obs ;

	if (!str) 
		return notify_fail("��Ҫ���������ϵ�ʲ�ᶫ��������أ�\n");

	if( str=="all" ) {
		obs = all_inventory(this_player());
		for( i=0; i<sizeof(obs); i++ ) {
			if( obs[i]->query("prevent_drop") || obs[i]->query("secure") )
				continue;
			if(obs[i]->query("wielded") || obs[i]->query("equipped") ) 
				continue;
			sell_ob(obs[i]);
		}
		return 1;
	} else {
	ob = present(str, this_player());
	if( !ob )
		return notify_fail("��û������������\n");
	if( ob->query("prevent_drop") || ob->query("secure") )
		return notify_fail("ɵС�ӣ����������Ѿ��б�ǲ��ܷ��׸���ۡ�\n");
	sell_ob(ob);
	}
	return 1;
}
