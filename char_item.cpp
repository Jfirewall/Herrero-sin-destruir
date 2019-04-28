buscas bool CHARACTER::DoRefine(LPITEM item, bool bMoneyOnly)

reemplazar:

		DBManager::instance().SendMoneyLog(MONEY_LOG_REFINE, item->GetVnum(), -cost);
		NotifyRefineFail(this, item, IsRefineThroughGuild() ? "GUILD" : "POWER");
		item->AttrLog();
		ITEM_MANAGER::instance().RemoveItem(item, "REMOVE (REFINE FAIL)");
		
con:

		DWORD result_fail_vnum = item->GetRefineFromVnum();
		LPITEM pkNewItem = ITEM_MANAGER::instance().CreateItem(result_fail_vnum, 1, 0, true);
		BYTE bCell = item->GetCell();
		ITEM_MANAGER::CopyAllAttrTo(item, pkNewItem);
		pkNewItem->AddToCharacter(this, TItemPos(INVENTORY, bCell)); 
