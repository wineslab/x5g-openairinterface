/*
 * Licensed to the OpenAirInterface (OAI) Software Alliance under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.
 * The OpenAirInterface Software Alliance licenses this file to You under
 * the OAI Public License, Version 1.1  (the "License"); you may not use this file
 * except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.openairinterface.org/?page_id=698
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *-------------------------------------------------------------------------------
 * For more information about the OpenAirInterface (OAI) Software Alliance:
 *      contact@openairinterface.org
 */

/*! \file f1ap_common.c
 * \brief f1ap procedures for both CU and DU
 * \author EURECOM/NTUST
 * \date 2018
 * \version 0.1
 * \company Eurecom
 * \email: navid.nikaein@eurecom.fr, bing-kai.hong@eurecom.fr
 * \note
 * \warning
 */

#include "f1ap_common.h"

#if defined(EMIT_ASN_DEBUG_EXTERN)
int asn_debug = 0;
int asn1_xer_print = 0;

inline void ASN_DEBUG(const char *fmt, ...)
{
  if (asn_debug) {
    int adi = asn_debug_indent;
    va_list ap;
    va_start(ap, fmt);
    fprintf(stderr, "[ASN1]");

    while(adi--) fprintf(stderr, " ");

    vfprintf(stderr, fmt, ap);
    fprintf(stderr, "\n");
    va_end(ap);
  }
}
#endif

/*
ssize_t f1ap_generate_initiating_message(
  uint8_t               **buffer,
  uint32_t               *length,
  e_F1ap_ProcedureCode    procedureCode,
  F1ap_Criticality_t      criticality,
  asn_TYPE_descriptor_t  *td,
  void                   *sptr)
{
  S1AP_PDU_t pdu;
  ssize_t    encoded;

  memset(&pdu, 0, sizeof(S1AP_PDU_t));

  pdu.present = S1AP_PDU_PR_initiatingMessage;
  pdu.choice.initiatingMessage.procedureCode = procedureCode;
  pdu.choice.initiatingMessage.criticality   = criticality;
  ANY_fromType_aper(&pdu.choice.initiatingMessage.value, td, sptr);

  if (asn1_xer_print) {
    xer_fprint(stdout, &asn_DEF_S1AP_PDU, (void *)&pdu);
  }*/

  /* We can safely free list of IE from sptr */
/*
  ASN_STRUCT_FREE_CONTENTS_ONLY(*td, sptr);

  if ((encoded = aper_encode_to_new_buffer(&asn_DEF_S1AP_PDU, 0, &pdu,
                 (void **)buffer)) < 0) {
    return -1;
  }

  *length = encoded;
  return encoded;
}

ssize_t f1ap_generate_successfull_outcome(
  uint8_t               **buffer,
  uint32_t               *length,
  e_F1ap_ProcedureCode         procedureCode,
  F1ap_Criticality_t           criticality,
  asn_TYPE_descriptor_t  *td,
  void                   *sptr)
{
  S1AP_PDU_t pdu;
  ssize_t    encoded;

  memset(&pdu, 0, sizeof(S1AP_PDU_t));

  pdu.present = S1AP_PDU_PR_successfulOutcome;
  pdu.choice.successfulOutcome.procedureCode = procedureCode;
  pdu.choice.successfulOutcome.criticality   = criticality;
  ANY_fromType_aper(&pdu.choice.successfulOutcome.value, td, sptr);

  if (asn1_xer_print) {
    xer_fprint(stdout, &asn_DEF_S1AP_PDU, (void *)&pdu);
  }*/

  /* We can safely free list of IE from sptr */
/*
  ASN_STRUCT_FREE_CONTENTS_ONLY(*td, sptr);

  if ((encoded = aper_encode_to_new_buffer(&asn_DEF_S1AP_PDU, 0, &pdu,
                 (void **)buffer)) < 0) {
    return -1;
  }

  *length = encoded;

  return encoded;
}

ssize_t f1ap_generate_unsuccessfull_outcome(
  uint8_t               **buffer,
  uint32_t               *length,
  e_F1ap_ProcedureCode         procedureCode,
  F1ap_Criticality_t           criticality,
  asn_TYPE_descriptor_t  *td,
  void                   *sptr)
{
  S1AP_PDU_t pdu;
  ssize_t    encoded;

  memset(&pdu, 0, sizeof(S1AP_PDU_t));

  pdu.present = S1AP_PDU_PR_unsuccessfulOutcome;
  pdu.choice.successfulOutcome.procedureCode = procedureCode;
  pdu.choice.successfulOutcome.criticality   = criticality;
  ANY_fromType_aper(&pdu.choice.successfulOutcome.value, td, sptr);

  if (asn1_xer_print) {
    xer_fprint(stdout, &asn_DEF_S1AP_PDU, (void *)&pdu);
  }
*/
  /* We can safely free list of IE from sptr */
/*
  ASN_STRUCT_FREE_CONTENTS_ONLY(*td, sptr);

  if ((encoded = aper_encode_to_new_buffer(&asn_DEF_S1AP_PDU, 0, &pdu,
                 (void **)buffer)) < 0) {
    return -1;
  }

  *length = encoded;

  return encoded;
}

F1ap_IE_t *f1ap_new_ie(
  F1ap_ProtocolIE_ID_t   id,
  F1ap_Criticality_t     criticality,
  asn_TYPE_descriptor_t *type,
  void                  *sptr)
{
  F1ap_IE_t *buff;

  if ((buff = malloc(sizeof(F1ap_IE_t))) == NULL) {
    // Possible error on malloc
    return NULL;
  }

  memset((void *)buff, 0, sizeof(F1ap_IE_t));

  buff->id = id;
  buff->criticality = criticality;

  if (ANY_fromType_aper(&buff->value, type, sptr) < 0) {
    fprintf(stderr, "Encoding of %s failed\n", type->name);
    free(buff);
    return NULL;
  }

  if (asn1_xer_print)
    if (xer_fprint(stdout, &asn_DEF_F1ap_IE, buff) < 0) {
      free(buff);
      return NULL;
    }

  return buff;
}

void f1ap_handle_criticality(F1ap_Criticality_t criticality)
{

}
*/

uint8_t F1AP_get_next_transaction_identifier(module_id_t enb_mod_idP, module_id_t cu_mod_idP)
{
  static uint8_t transaction_identifier[NUMBER_OF_eNB_MAX];
  transaction_identifier[enb_mod_idP+cu_mod_idP] =
      (transaction_identifier[enb_mod_idP+cu_mod_idP] + 1) % F1AP_TRANSACTION_IDENTIFIER_NUMBER;
  //LOG_T(F1AP,"generated xid is %d\n",transaction_identifier[enb_mod_idP+cu_mod_idP]);
  return transaction_identifier[enb_mod_idP+cu_mod_idP];
}

module_id_t F1AP_get_UE_identifier(module_id_t enb_mod_idP, int CC_idP, int UE_id) {  
  static module_id_t      UE_identifier[NUMBER_OF_eNB_MAX];
  UE_identifier[enb_mod_idP+CC_idP+UE_id] = (UE_identifier[enb_mod_idP+CC_idP+UE_id] + 1) % F1AP_UE_IDENTIFIER_NUMBER;
  //LOG_T(F1AP,"generated xid is %d\n",transaction_identifier[enb_mod_idP+du_mod_idP]);
  return UE_identifier[enb_mod_idP+CC_idP+UE_id];
}

int f1ap_add_ue(f1ap_cudu_ue_inst_t *f1_ue_inst, 
                module_id_t          module_idP,
                int                  CC_idP,
                int                  UE_id,
                rnti_t               rntiP){

  int i;
  for (i=0; i < MAX_MOBILES_PER_ENB; i++){
    if (f1_ue_inst->rnti[i] == rntiP) {
       f1_ue_inst->f1ap_uid[i] = i; 
       f1_ue_inst->mac_uid[i] = UE_id;    
       LOG_I(F1AP, "Updating the index of UE with RNTI %x and du_ue_f1ap_id %d\n", f1_ue_inst->rnti[i], f1_ue_inst->du_ue_f1ap_id[i]);
       return i;
    }
  }
  for (i=0; i < MAX_MOBILES_PER_ENB ; i++){
    if (f1_ue_inst->rnti[i] == 0 ){
       f1_ue_inst->rnti[i]=rntiP;
       f1_ue_inst->f1ap_uid[i]=i;
       f1_ue_inst->mac_uid[i]=UE_id;
       f1_ue_inst->du_ue_f1ap_id[i] = F1AP_get_UE_identifier(module_idP, CC_idP, i);
       f1_ue_inst->cu_ue_f1ap_id[i] = F1AP_get_UE_identifier(module_idP, CC_idP, i);
       f1_ue_inst->num_ues++;
       LOG_I(F1AP, "Adding a new UE with RNTI %x and cu/du ue_f1ap_id %d\n", f1_ue_inst->rnti[i], f1_ue_inst->du_ue_f1ap_id[i]);
      return i;
    }
  }
  return -1;
}


int f1ap_remove_ue(f1ap_cudu_ue_inst_t *f1_ue_inst,
                  rnti_t          rntiP){

  int i;
  for (i=0; i < MAX_MOBILES_PER_ENB; i++){
    if (f1_ue_inst->rnti[i] == rntiP) {
       f1_ue_inst->rnti[i] = 0;    
       break;
    }
  }
  return 0 ;
}

int f1ap_get_du_ue_f1ap_id (f1ap_cudu_ue_inst_t *f1_ue_inst,
                            rnti_t          rntiP){

  int i;
  for (i=0; i < MAX_MOBILES_PER_ENB; i++){
    if (f1_ue_inst->rnti[i] == rntiP) {
      return f1_ue_inst->du_ue_f1ap_id[i];
    }
 }
 return -1;
}

int f1ap_get_cu_ue_f1ap_id (f1ap_cudu_ue_inst_t *f1_ue_inst,
                            rnti_t          rntiP){

  int i;
  for (i=0; i < MAX_MOBILES_PER_ENB; i++){
    if (f1_ue_inst->rnti[i] == rntiP) {
      return f1_ue_inst->cu_ue_f1ap_id[i];
    }
 }
 return -1;
}

int f1ap_get_rnti_by_du_id(f1ap_cudu_ue_inst_t *f1_ue_inst,
                           module_id_t          du_ue_f1ap_id ){

  int i;
  for (i=0; i < MAX_MOBILES_PER_ENB; i++){
    if (f1_ue_inst->du_ue_f1ap_id[i] == du_ue_f1ap_id) {
      return f1_ue_inst->rnti[i];
    } 
 }
 return -1;
}

int f1ap_get_rnti_by_cu_id(f1ap_cudu_ue_inst_t *f1_ue_inst,
                           module_id_t          cu_ue_f1ap_id ){

  int i;
  for (i=0; i < MAX_MOBILES_PER_ENB; i++){
    if (f1_ue_inst->cu_ue_f1ap_id[i] == cu_ue_f1ap_id) {
      return f1_ue_inst->rnti[i];
    } 
 }
 return -1;
}

int f1ap_get_du_uid(f1ap_cudu_ue_inst_t *f1_ue_inst,
                    module_id_t      du_ue_f1ap_id ){

  int i;
  for (i=0; i < MAX_MOBILES_PER_ENB; i++){
    if (f1_ue_inst->du_ue_f1ap_id[i] == du_ue_f1ap_id) {
      return i;
    } 
 }
 return -1;
}


int f1ap_get_cu_uid(f1ap_cudu_ue_inst_t *f1_ue_inst,
                    module_id_t      cu_ue_f1ap_id ){

  int i;
  for (i=0; i < MAX_MOBILES_PER_ENB; i++){
    if (f1_ue_inst->cu_ue_f1ap_id[i] == cu_ue_f1ap_id) {
      return i;
    } 
 }
 return -1;
}

int f1ap_get_uid_by_rnti(f1ap_cudu_ue_inst_t *f1_ue_inst,
                         rnti_t          rntiP ){

  int i;
  for (i=0; i < MAX_MOBILES_PER_ENB; i++){
    if (f1_ue_inst->rnti[i] == rntiP) {
      return i;
    } 
 }
 return -1;
}

int f1ap_du_add_cu_ue_id(f1ap_cudu_ue_inst_t *f1_ue_inst,
                         module_id_t du_ue_f1ap_id,
                         module_id_t cu_ue_f1ap_id){
    module_id_t f1ap_uid = f1ap_get_du_uid(f1_ue_inst,du_ue_f1ap_id);
    if (f1ap_uid < 0 )
      return -1 ;
    f1_ue_inst->cu_ue_f1ap_id[f1ap_uid]=cu_ue_f1ap_id;
    LOG_I(F1AP, "Adding cu_ue_f1ap_id %d for UE with RNTI %x \n", cu_ue_f1ap_id, f1_ue_inst->rnti[f1ap_uid]);
    return 0 ;
}

int f1ap_cu_add_du_ue_id(f1ap_cudu_ue_inst_t *f1_ue_inst,
                         module_id_t cu_ue_f1ap_id,
                         module_id_t du_ue_f1ap_id){
    module_id_t f1ap_uid = f1ap_get_cu_uid(f1_ue_inst,cu_ue_f1ap_id);
    if (f1ap_uid < 0 )
      return -1 ;
    f1_ue_inst->du_ue_f1ap_id[f1ap_uid]=du_ue_f1ap_id;
    LOG_I(F1AP, "Adding du_ue_f1ap_id %d for UE with RNTI %x \n", du_ue_f1ap_id, f1_ue_inst->rnti[f1ap_uid]);
    return 0 ;
}