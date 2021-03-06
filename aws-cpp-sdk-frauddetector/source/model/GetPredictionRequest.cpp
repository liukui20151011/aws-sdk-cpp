﻿/*
* Copyright 2010-2017 Amazon.com, Inc. or its affiliates. All Rights Reserved.
*
* Licensed under the Apache License, Version 2.0 (the "License").
* You may not use this file except in compliance with the License.
* A copy of the License is located at
*
*  http://aws.amazon.com/apache2.0
*
* or in the "license" file accompanying this file. This file is distributed
* on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either
* express or implied. See the License for the specific language governing
* permissions and limitations under the License.
*/

#include <aws/frauddetector/model/GetPredictionRequest.h>
#include <aws/core/utils/json/JsonSerializer.h>

#include <utility>

using namespace Aws::FraudDetector::Model;
using namespace Aws::Utils::Json;
using namespace Aws::Utils;

GetPredictionRequest::GetPredictionRequest() : 
    m_detectorIdHasBeenSet(false),
    m_detectorVersionIdHasBeenSet(false),
    m_eventIdHasBeenSet(false),
    m_eventAttributesHasBeenSet(false),
    m_externalModelEndpointDataBlobsHasBeenSet(false)
{
}

Aws::String GetPredictionRequest::SerializePayload() const
{
  JsonValue payload;

  if(m_detectorIdHasBeenSet)
  {
   payload.WithString("detectorId", m_detectorId);

  }

  if(m_detectorVersionIdHasBeenSet)
  {
   payload.WithString("detectorVersionId", m_detectorVersionId);

  }

  if(m_eventIdHasBeenSet)
  {
   payload.WithString("eventId", m_eventId);

  }

  if(m_eventAttributesHasBeenSet)
  {
   JsonValue eventAttributesJsonMap;
   for(auto& eventAttributesItem : m_eventAttributes)
   {
     eventAttributesJsonMap.WithString(eventAttributesItem.first, eventAttributesItem.second);
   }
   payload.WithObject("eventAttributes", std::move(eventAttributesJsonMap));

  }

  if(m_externalModelEndpointDataBlobsHasBeenSet)
  {
   JsonValue externalModelEndpointDataBlobsJsonMap;
   for(auto& externalModelEndpointDataBlobsItem : m_externalModelEndpointDataBlobs)
   {
     externalModelEndpointDataBlobsJsonMap.WithObject(externalModelEndpointDataBlobsItem.first, externalModelEndpointDataBlobsItem.second.Jsonize());
   }
   payload.WithObject("externalModelEndpointDataBlobs", std::move(externalModelEndpointDataBlobsJsonMap));

  }

  return payload.View().WriteReadable();
}

Aws::Http::HeaderValueCollection GetPredictionRequest::GetRequestSpecificHeaders() const
{
  Aws::Http::HeaderValueCollection headers;
  headers.insert(Aws::Http::HeaderValuePair("X-Amz-Target", "AWSHawksNestServiceFacade.GetPrediction"));
  return headers;

}




