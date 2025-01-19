// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Widget/AuraUserWidget.h"

void UAuraUserWidget::SetWidgetController(UObject* InWidgetController)
{
	WidgetController = InWidgetController;
	WidgetControllerSet(); // This is blueprint implementable, so logic happens in BP
}
